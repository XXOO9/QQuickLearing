/* LiteSQL 
 * 
 * The list of contributors at http://litesql.sf.net/ 
 * 
 * See LICENSE for copyright information. */

#ifndef litesql_database_hpp
#define litesql_database_hpp
#include <string>
#include <set>
#include "litesql/types.hpp"
#include "litesql/expr.hpp"
#include "litesql/backend.hpp"
#include "litesql/cursor.hpp"
/** \file database.hpp
    Database-class
*/

namespace litesql {
using namespace std;

class ColumnDefinition {
public:
  std::string name;
  std::string type;

  class EqualName {
    std::string m_name;
  public: 
    EqualName(const std::string& name) : m_name(name) {};
    bool operator()(ColumnDefinition d) { return d.name==m_name;};
  };
};

/** A base class of databases. Can be used without inheriting own version of
    Database using query()-method. See \ref usage_defining_database */
class Database {    
  friend class Updater;
private:
    /** name of the backend */
    std::string backendType;
    /** connection info "param=value param=value ..." */
    std::string connInfo;
    /** assignment is forbidden */
    Database &operator=(const Database &op)=delete;
    /** opens connection to backend */
	void openDatabase() noexcept(false); // throw(DatabaseError);
protected:
    /** backend implementation */
    unique_ptr<Backend> backend;
    /** intermediate representation of single entity in relational database,
        table, index or sequence */
    class SchemaItem {
    public:
        std::string name, type, sql;
        SchemaItem(const std::string& n, const std::string& t, const std::string& s) 
            : name(n), type(t), sql(s) {}
    };
    /** stores SchemaItem to 'schema' - table (deletes old versions) */
    void storeSchemaItem(const SchemaItem& s) const;
    /** returns database schema.
        \return SchemaItem-objects */
    virtual std::vector<SchemaItem> getSchema() const { 
        return std::vector<SchemaItem>(); 
    }
    /** queries 'schema' - table and converts results to SchemaItem-objects
        \return SchemaItem-objects */
    std::vector<SchemaItem> getCurrentSchema() const;
    /** adds missing and removes extra fields to/from table 
        (tries to preserve data).
        copies data to a temporary table and then back to upgraded table
        because all backends do not support 
        ALTER TABLE ADD ... - SQL statements. 
    \param name table name
    \param oldSchema current schema of table 
    \param newSchema upgraded schema of table */
    void upgradeTable(std::string name, std::string oldSchema, std::string newSchema) const;

    bool addColumn(const std::string & name,const ColumnDefinition & column_def) const;

public:
    /** verbosity, prints queries to cerr if true */
   bool verbose;
    /** opens connection to backend, throw exception if fails or cannot
        found a Backend class
        \param backendType backend type ("postgresql","mysql" or "sqlite3")
        \param connInfo connection params, syntax "param=value param=value ..."
               valid keys: host,user,password,database and port 
      */
    Database(const std::string& backendType, const std::string& connInfo);
    /** opens new connection to same database 
        \param op opened Database */
    Database(const Database &op);
    /** closes database */
    virtual ~Database();
    /** creates database based on getSchema */
    void create() const;
    /** converts CREATE-statements (of getSchema) 
     *  to DROP statements and executes them */
    void drop() const;
    /** returns true if schema of backend database is different from schema
        returned by getSchema. */
    bool needsUpgrade() const;
    /** tries to upgrade database on disk so that schemas would be compatible */
    void upgrade() const;
    /** executes SQL query 
        \param query query std::string 
        \return result set */
    Records query(const std::string &query) const;
    template <class T> 
        Cursor<T> cursor(const std::string& query) const {
        if (verbose)
            cerr << query << endl;
        return Cursor<T>(*this, backend->cursor(query));
    }

    /** executes SQL INSERT statement.
        \param table destination table
        \param r values
        \param fields field names
        Values are escaped using escapeSQL - function */
    
    void insert(const std::string &table, const Record &r,
                const Split& fields=Split()) const;
    /** executes multiple INSERT-statements and assigns same 'row id'
        for first field of every record
        \param tables destination tables for insert operation
        \param fields record of field names per table
        \param values record of values per table
        \param sequence sequence where row id-numbers are pulled
        \return new row id */
    std::string groupInsert(const Record& tables, 
                       const Records& fields, 
                       const Records& values, 
                       const std::string& sequence) const;
    /** deletes rows from single table, deleted rows are selected by Expr 
        if specified
        \param table target table
        \param e selection expression */
    void delete_(const std::string &table, const Expr& e= Expr()) const; 
    /** begins SQL transaction */
    void begin() const { backend->begin(); }
    /** commits SQL transaction */
    void commit() const { backend->commit(); }
    /** cancels active SQL transaction */
    void rollback() const { backend->rollback(); }  
};

}

#endif
