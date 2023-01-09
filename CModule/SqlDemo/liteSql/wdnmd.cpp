#include "wdnmd.hpp"
namespace example {
using namespace litesql;
const litesql::FieldType userInfo::Own::Id("id_",A_field_type_integer,"userInfo_");
const std::string userInfo::type__("userInfo");
const std::string userInfo::table__("userInfo_");
const std::string userInfo::sequence__("userInfo_seq");
const litesql::FieldType userInfo::Id("id_",A_field_type_integer,table__);
const litesql::FieldType userInfo::Type("type_",A_field_type_string,table__);
const litesql::FieldType userInfo::UserName("userName_",A_field_type_string,table__);
const litesql::FieldType userInfo::Age("age_",A_field_type_integer,table__);
void userInfo::initValues() {
}
void userInfo::defaults() {
    id = 0;
    age = 0;
}
userInfo::userInfo(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), userName(UserName), age(Age) {
    defaults();
}
userInfo::userInfo(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), userName(UserName), age(Age) {
    defaults();
    size_t size = (rec.size() > 4) ? 4 : rec.size();
    switch(size) {
    case 4: age = convert<const std::string&, int>(rec[3]);
        age.setModified(false);
    case 3: userName = convert<const std::string&, std::string>(rec[2]);
        userName.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
userInfo::userInfo(const userInfo& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), userName(obj.userName), age(obj.age) {
}
const userInfo& userInfo::operator=(const userInfo& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        userName = obj.userName;
        age = obj.age;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string userInfo::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(userName.name());
    values.push_back(userName);
    userName.setModified(false);
    fields.push_back(age.name());
    values.push_back(age);
    age.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void userInfo::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void userInfo::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, userName);
    updateField(updates, table__, age);
}
void userInfo::addIDUpdates(Updates& updates) {
}
void userInfo::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(UserName);
    ftypes.push_back(Age);
}
void userInfo::delRecord() {
    deleteFromTable(table__, id);
}
void userInfo::delRelations() {
}
void userInfo::update() {
    if (!inDatabase) {
        create();
        return;
    }
    Updates updates;
    addUpdates(updates);
    if (id != oldKey) {
        if (!typeIsCorrect()) 
            upcastCopy()->addIDUpdates(updates);
    }
    litesql::Persistent::update(updates);
    oldKey = id;
}
void userInfo::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<userInfo> p(upcastCopy());
        p->delRelations();
        p->onDelete();
        p->delRecord();
    } else {
        delRelations();
        onDelete();
        delRecord();
    }
    inDatabase = false;
}
bool userInfo::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<userInfo> userInfo::upcast() const {
    return unique_ptr<userInfo>(new userInfo(*this));
}
std::unique_ptr<userInfo> userInfo::upcastCopy() const {
    userInfo* np = new userInfo(*this);
    np->id = id;
    np->type = type;
    np->userName = userName;
    np->age = age;
    np->inDatabase = inDatabase;
    return unique_ptr<userInfo>(np);
}
std::ostream & operator<<(std::ostream& os, userInfo o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.userName.name() << " = " << o.userName << std::endl;
    os << o.age.name() << " = " << o.age << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
WDNMD::WDNMD(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> WDNMD::getSchema() const {
    vector<Database::SchemaItem> res;
    string TEXT = backend->getSQLType(A_field_type_string);
    string rowIdType = backend->getRowIDType();
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ "+TEXT+", type_ "+TEXT+", sql_ "+TEXT+")"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("userInfo_seq","sequence",backend->getCreateSequenceSQL("userInfo_seq")));
    }
    res.push_back(Database::SchemaItem("userInfo_","table","CREATE TABLE userInfo_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",userName_ " + backend->getSQLType(A_field_type_string,"") + "" +",age_ " + backend->getSQLType(A_field_type_integer,"") + "" +")"));
    res.push_back(Database::SchemaItem("userInfo_id_idx","index","CREATE INDEX userInfo_id_idx ON userInfo_ (id_)"));
    return res;
}
void WDNMD::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
}
}
