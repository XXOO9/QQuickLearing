#ifndef wdnmd_hpp
#define wdnmd_hpp
#include "litesql.hpp"
namespace example {
class userInfo;
class userInfo : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class SexType : public litesql::FieldType {
    public:
        static const int Male;
        static const int Female;
        SexType(const std::string& n, AT_field_type t, const std::string& tbl, const litesql::FieldType::Values& vals=Values());
    };
    class Sex {
    public:
        static const int Male;
        static const int Female;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType UserName;
    litesql::Field<std::string> userName;
    static const litesql::FieldType Age;
    litesql::Field<int> age;
protected:
    static std::vector < std::pair< std::string, std::string > > sex_values;
public:
    static const litesql::FieldType Sex;
    litesql::Field<int> sex;
    static void initValues();
protected:
    void defaults();
public:
    userInfo(const litesql::Database& db);
    userInfo(const litesql::Database& db, const litesql::Record& rec);
    userInfo(const userInfo& obj);
    const userInfo& operator=(const userInfo& obj);
    virtual void introduce();
    virtual void recvParam(std::string newName);
protected:
    std::string insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs);
    void create();
    virtual void addUpdates(Updates& updates);
    virtual void addIDUpdates(Updates& updates);
public:
    static void getFieldTypes(std::vector<litesql::FieldType>& ftypes);
protected:
    virtual void delRecord();
    virtual void delRelations();
public:
    virtual void update();
    virtual void del();
    virtual bool typeIsCorrect() const;
    std::unique_ptr<userInfo> upcast() const;
    std::unique_ptr<userInfo> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, userInfo o);
class WDNMD : public litesql::Database {
public:
    WDNMD(std::string backendType, std::string connInfo);
protected:
    virtual std::vector<litesql::Database::SchemaItem> getSchema() const;
    static void initialize();
};
}
#endif
