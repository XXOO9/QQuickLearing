#include "eps100database.hpp"
namespace EPSDatabase {
using namespace litesql;
const litesql::FieldType ConfigVersion::Own::Id("id_",A_field_type_integer,"ConfigVersion_");
const std::string ConfigVersion::type__("ConfigVersion");
const std::string ConfigVersion::table__("ConfigVersion_");
const std::string ConfigVersion::sequence__("ConfigVersion_seq");
const litesql::FieldType ConfigVersion::Id("id_",A_field_type_integer,table__);
const litesql::FieldType ConfigVersion::Type("type_",A_field_type_string,table__);
const litesql::FieldType ConfigVersion::CfgVersion("cfgVersion_",A_field_type_string,table__);
void ConfigVersion::initValues() {
}
void ConfigVersion::defaults() {
    id = 0;
}
ConfigVersion::ConfigVersion(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), cfgVersion(CfgVersion) {
    defaults();
}
ConfigVersion::ConfigVersion(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), cfgVersion(CfgVersion) {
    defaults();
    size_t size = (rec.size() > 3) ? 3 : rec.size();
    switch(size) {
    case 3: cfgVersion = convert<const std::string&, std::string>(rec[2]);
        cfgVersion.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
ConfigVersion::ConfigVersion(const ConfigVersion& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), cfgVersion(obj.cfgVersion) {
}
const ConfigVersion& ConfigVersion::operator=(const ConfigVersion& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        cfgVersion = obj.cfgVersion;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string ConfigVersion::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(cfgVersion.name());
    values.push_back(cfgVersion);
    cfgVersion.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void ConfigVersion::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void ConfigVersion::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, cfgVersion);
}
void ConfigVersion::addIDUpdates(Updates& updates) {
}
void ConfigVersion::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(CfgVersion);
}
void ConfigVersion::delRecord() {
    deleteFromTable(table__, id);
}
void ConfigVersion::delRelations() {
}
void ConfigVersion::update() {
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
void ConfigVersion::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<ConfigVersion> p(upcastCopy());
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
bool ConfigVersion::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<ConfigVersion> ConfigVersion::upcast() const {
    return unique_ptr<ConfigVersion>(new ConfigVersion(*this));
}
std::unique_ptr<ConfigVersion> ConfigVersion::upcastCopy() const {
    ConfigVersion* np = new ConfigVersion(*this);
    np->id = id;
    np->type = type;
    np->cfgVersion = cfgVersion;
    np->inDatabase = inDatabase;
    return unique_ptr<ConfigVersion>(np);
}
std::ostream & operator<<(std::ostream& os, ConfigVersion o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.cfgVersion.name() << " = " << o.cfgVersion << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType DataSyncTime::Own::Id("id_",A_field_type_integer,"DataSyncTime_");
const std::string DataSyncTime::type__("DataSyncTime");
const std::string DataSyncTime::table__("DataSyncTime_");
const std::string DataSyncTime::sequence__("DataSyncTime_seq");
const litesql::FieldType DataSyncTime::Id("id_",A_field_type_integer,table__);
const litesql::FieldType DataSyncTime::Type("type_",A_field_type_string,table__);
const litesql::FieldType DataSyncTime::LastSyncTime("lastSyncTime_",A_field_type_string,table__);
void DataSyncTime::initValues() {
}
void DataSyncTime::defaults() {
    id = 0;
}
DataSyncTime::DataSyncTime(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), lastSyncTime(LastSyncTime) {
    defaults();
}
DataSyncTime::DataSyncTime(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), lastSyncTime(LastSyncTime) {
    defaults();
    size_t size = (rec.size() > 3) ? 3 : rec.size();
    switch(size) {
    case 3: lastSyncTime = convert<const std::string&, std::string>(rec[2]);
        lastSyncTime.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
DataSyncTime::DataSyncTime(const DataSyncTime& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), lastSyncTime(obj.lastSyncTime) {
}
const DataSyncTime& DataSyncTime::operator=(const DataSyncTime& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        lastSyncTime = obj.lastSyncTime;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string DataSyncTime::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(lastSyncTime.name());
    values.push_back(lastSyncTime);
    lastSyncTime.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void DataSyncTime::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void DataSyncTime::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, lastSyncTime);
}
void DataSyncTime::addIDUpdates(Updates& updates) {
}
void DataSyncTime::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(LastSyncTime);
}
void DataSyncTime::delRecord() {
    deleteFromTable(table__, id);
}
void DataSyncTime::delRelations() {
}
void DataSyncTime::update() {
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
void DataSyncTime::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<DataSyncTime> p(upcastCopy());
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
bool DataSyncTime::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<DataSyncTime> DataSyncTime::upcast() const {
    return unique_ptr<DataSyncTime>(new DataSyncTime(*this));
}
std::unique_ptr<DataSyncTime> DataSyncTime::upcastCopy() const {
    DataSyncTime* np = new DataSyncTime(*this);
    np->id = id;
    np->type = type;
    np->lastSyncTime = lastSyncTime;
    np->inDatabase = inDatabase;
    return unique_ptr<DataSyncTime>(np);
}
std::ostream & operator<<(std::ostream& os, DataSyncTime o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.lastSyncTime.name() << " = " << o.lastSyncTime << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType UserIdentityInfo::Own::Id("id_",A_field_type_integer,"UserIdentityInfo_");
const int UserIdentityInfo::RoleTypeType::UNKNOW(-1);
const int UserIdentityInfo::RoleTypeType::GUEST(0);
const int UserIdentityInfo::RoleTypeType::NORMAL(1);
const int UserIdentityInfo::RoleTypeType::ADMIN(2);
UserIdentityInfo::RoleTypeType::RoleTypeType(const std::string& n, AT_field_type t, const std::string& tbl, const litesql::FieldType::Values& vals)
         : litesql::FieldType(n,t,tbl,vals) {
}
const int UserIdentityInfo::RoleType::UNKNOW(-1);
const int UserIdentityInfo::RoleType::GUEST(0);
const int UserIdentityInfo::RoleType::NORMAL(1);
const int UserIdentityInfo::RoleType::ADMIN(2);
const int UserIdentityInfo::GenderType::MALE(1);
const int UserIdentityInfo::GenderType::FEMALE(0);
UserIdentityInfo::GenderType::GenderType(const std::string& n, AT_field_type t, const std::string& tbl, const litesql::FieldType::Values& vals)
         : litesql::FieldType(n,t,tbl,vals) {
}
const int UserIdentityInfo::Gender::MALE(1);
const int UserIdentityInfo::Gender::FEMALE(0);
const std::string UserIdentityInfo::type__("UserIdentityInfo");
const std::string UserIdentityInfo::table__("UserIdentityInfo_");
const std::string UserIdentityInfo::sequence__("UserIdentityInfo_seq");
const litesql::FieldType UserIdentityInfo::Id("id_",A_field_type_integer,table__);
const litesql::FieldType UserIdentityInfo::Type("type_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::CodeUniqueID("codeUniqueID_",A_field_type_string,table__);
std::vector < std::pair< std::string, std::string > > UserIdentityInfo::roleType_values;
const litesql::FieldType UserIdentityInfo::RoleType("roleType_",A_field_type_integer,table__);
const litesql::FieldType UserIdentityInfo::Name("name_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::Brithday("brithday_",A_field_type_string,table__);
std::vector < std::pair< std::string, std::string > > UserIdentityInfo::gender_values;
const litesql::FieldType UserIdentityInfo::Gender("gender_",A_field_type_integer,table__);
const litesql::FieldType UserIdentityInfo::StudentID("studentID_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::IDCardNo("iDCardNo_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::IDMagCard("iDMagCard_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::NGrade("nGrade_",A_field_type_integer,table__);
const litesql::FieldType UserIdentityInfo::NClass("nClass_",A_field_type_integer,table__);
const litesql::FieldType UserIdentityInfo::Nation("nation_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::FaceFeature("faceFeature_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::FaceImagePath("faceImagePath_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::CampusMagcard("campusMagcard_",A_field_type_string,table__);
const litesql::FieldType UserIdentityInfo::TimeStamp("timeStamp_",A_field_type_string,table__);
void UserIdentityInfo::initValues() {
    roleType_values.clear();
    roleType_values.push_back(make_pair<std::string, std::string>("UNKNOW","-1"));
    roleType_values.push_back(make_pair<std::string, std::string>("GUEST","0"));
    roleType_values.push_back(make_pair<std::string, std::string>("NORMAL","1"));
    roleType_values.push_back(make_pair<std::string, std::string>("ADMIN","2"));
    gender_values.clear();
    gender_values.push_back(make_pair<std::string, std::string>("MALE","1"));
    gender_values.push_back(make_pair<std::string, std::string>("FEMALE","0"));
}
void UserIdentityInfo::defaults() {
    id = 0;
    roleType = 0;
    gender = 0;
    nGrade = 0;
    nClass = 0;
}
UserIdentityInfo::UserIdentityInfo(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), codeUniqueID(CodeUniqueID), roleType(RoleType), name(Name), brithday(Brithday), gender(Gender), studentID(StudentID), iDCardNo(IDCardNo), iDMagCard(IDMagCard), nGrade(NGrade), nClass(NClass), nation(Nation), faceFeature(FaceFeature), faceImagePath(FaceImagePath), campusMagcard(CampusMagcard), timeStamp(TimeStamp) {
    defaults();
}
UserIdentityInfo::UserIdentityInfo(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), codeUniqueID(CodeUniqueID), roleType(RoleType), name(Name), brithday(Brithday), gender(Gender), studentID(StudentID), iDCardNo(IDCardNo), iDMagCard(IDMagCard), nGrade(NGrade), nClass(NClass), nation(Nation), faceFeature(FaceFeature), faceImagePath(FaceImagePath), campusMagcard(CampusMagcard), timeStamp(TimeStamp) {
    defaults();
    size_t size = (rec.size() > 17) ? 17 : rec.size();
    switch(size) {
    case 17: timeStamp = convert<const std::string&, std::string>(rec[16]);
        timeStamp.setModified(false);
    case 16: campusMagcard = convert<const std::string&, std::string>(rec[15]);
        campusMagcard.setModified(false);
    case 15: faceImagePath = convert<const std::string&, std::string>(rec[14]);
        faceImagePath.setModified(false);
    case 14: faceFeature = convert<const std::string&, std::string>(rec[13]);
        faceFeature.setModified(false);
    case 13: nation = convert<const std::string&, std::string>(rec[12]);
        nation.setModified(false);
    case 12: nClass = convert<const std::string&, int>(rec[11]);
        nClass.setModified(false);
    case 11: nGrade = convert<const std::string&, int>(rec[10]);
        nGrade.setModified(false);
    case 10: iDMagCard = convert<const std::string&, std::string>(rec[9]);
        iDMagCard.setModified(false);
    case 9: iDCardNo = convert<const std::string&, std::string>(rec[8]);
        iDCardNo.setModified(false);
    case 8: studentID = convert<const std::string&, std::string>(rec[7]);
        studentID.setModified(false);
    case 7: gender = convert<const std::string&, int>(rec[6]);
        gender.setModified(false);
    case 6: brithday = convert<const std::string&, std::string>(rec[5]);
        brithday.setModified(false);
    case 5: name = convert<const std::string&, std::string>(rec[4]);
        name.setModified(false);
    case 4: roleType = convert<const std::string&, int>(rec[3]);
        roleType.setModified(false);
    case 3: codeUniqueID = convert<const std::string&, std::string>(rec[2]);
        codeUniqueID.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
UserIdentityInfo::UserIdentityInfo(const UserIdentityInfo& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), codeUniqueID(obj.codeUniqueID), roleType(obj.roleType), name(obj.name), brithday(obj.brithday), gender(obj.gender), studentID(obj.studentID), iDCardNo(obj.iDCardNo), iDMagCard(obj.iDMagCard), nGrade(obj.nGrade), nClass(obj.nClass), nation(obj.nation), faceFeature(obj.faceFeature), faceImagePath(obj.faceImagePath), campusMagcard(obj.campusMagcard), timeStamp(obj.timeStamp) {
}
const UserIdentityInfo& UserIdentityInfo::operator=(const UserIdentityInfo& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        codeUniqueID = obj.codeUniqueID;
        roleType = obj.roleType;
        name = obj.name;
        brithday = obj.brithday;
        gender = obj.gender;
        studentID = obj.studentID;
        iDCardNo = obj.iDCardNo;
        iDMagCard = obj.iDMagCard;
        nGrade = obj.nGrade;
        nClass = obj.nClass;
        nation = obj.nation;
        faceFeature = obj.faceFeature;
        faceImagePath = obj.faceImagePath;
        campusMagcard = obj.campusMagcard;
        timeStamp = obj.timeStamp;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string UserIdentityInfo::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(codeUniqueID.name());
    values.push_back(codeUniqueID);
    codeUniqueID.setModified(false);
    fields.push_back(roleType.name());
    values.push_back(roleType);
    roleType.setModified(false);
    fields.push_back(name.name());
    values.push_back(name);
    name.setModified(false);
    fields.push_back(brithday.name());
    values.push_back(brithday);
    brithday.setModified(false);
    fields.push_back(gender.name());
    values.push_back(gender);
    gender.setModified(false);
    fields.push_back(studentID.name());
    values.push_back(studentID);
    studentID.setModified(false);
    fields.push_back(iDCardNo.name());
    values.push_back(iDCardNo);
    iDCardNo.setModified(false);
    fields.push_back(iDMagCard.name());
    values.push_back(iDMagCard);
    iDMagCard.setModified(false);
    fields.push_back(nGrade.name());
    values.push_back(nGrade);
    nGrade.setModified(false);
    fields.push_back(nClass.name());
    values.push_back(nClass);
    nClass.setModified(false);
    fields.push_back(nation.name());
    values.push_back(nation);
    nation.setModified(false);
    fields.push_back(faceFeature.name());
    values.push_back(faceFeature);
    faceFeature.setModified(false);
    fields.push_back(faceImagePath.name());
    values.push_back(faceImagePath);
    faceImagePath.setModified(false);
    fields.push_back(campusMagcard.name());
    values.push_back(campusMagcard);
    campusMagcard.setModified(false);
    fields.push_back(timeStamp.name());
    values.push_back(timeStamp);
    timeStamp.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void UserIdentityInfo::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void UserIdentityInfo::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, codeUniqueID);
    updateField(updates, table__, roleType);
    updateField(updates, table__, name);
    updateField(updates, table__, brithday);
    updateField(updates, table__, gender);
    updateField(updates, table__, studentID);
    updateField(updates, table__, iDCardNo);
    updateField(updates, table__, iDMagCard);
    updateField(updates, table__, nGrade);
    updateField(updates, table__, nClass);
    updateField(updates, table__, nation);
    updateField(updates, table__, faceFeature);
    updateField(updates, table__, faceImagePath);
    updateField(updates, table__, campusMagcard);
    updateField(updates, table__, timeStamp);
}
void UserIdentityInfo::addIDUpdates(Updates& updates) {
}
void UserIdentityInfo::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(CodeUniqueID);
    ftypes.push_back(RoleType);
    ftypes.push_back(Name);
    ftypes.push_back(Brithday);
    ftypes.push_back(Gender);
    ftypes.push_back(StudentID);
    ftypes.push_back(IDCardNo);
    ftypes.push_back(IDMagCard);
    ftypes.push_back(NGrade);
    ftypes.push_back(NClass);
    ftypes.push_back(Nation);
    ftypes.push_back(FaceFeature);
    ftypes.push_back(FaceImagePath);
    ftypes.push_back(CampusMagcard);
    ftypes.push_back(TimeStamp);
}
void UserIdentityInfo::delRecord() {
    deleteFromTable(table__, id);
}
void UserIdentityInfo::delRelations() {
}
void UserIdentityInfo::update() {
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
void UserIdentityInfo::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<UserIdentityInfo> p(upcastCopy());
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
bool UserIdentityInfo::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<UserIdentityInfo> UserIdentityInfo::upcast() const {
    return unique_ptr<UserIdentityInfo>(new UserIdentityInfo(*this));
}
std::unique_ptr<UserIdentityInfo> UserIdentityInfo::upcastCopy() const {
    UserIdentityInfo* np = new UserIdentityInfo(*this);
    np->id = id;
    np->type = type;
    np->codeUniqueID = codeUniqueID;
    np->roleType = roleType;
    np->name = name;
    np->brithday = brithday;
    np->gender = gender;
    np->studentID = studentID;
    np->iDCardNo = iDCardNo;
    np->iDMagCard = iDMagCard;
    np->nGrade = nGrade;
    np->nClass = nClass;
    np->nation = nation;
    np->faceFeature = faceFeature;
    np->faceImagePath = faceImagePath;
    np->campusMagcard = campusMagcard;
    np->timeStamp = timeStamp;
    np->inDatabase = inDatabase;
    return unique_ptr<UserIdentityInfo>(np);
}
std::ostream & operator<<(std::ostream& os, UserIdentityInfo o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.codeUniqueID.name() << " = " << o.codeUniqueID << std::endl;
    os << o.roleType.name() << " = " << o.roleType << std::endl;
    os << o.name.name() << " = " << o.name << std::endl;
    os << o.brithday.name() << " = " << o.brithday << std::endl;
    os << o.gender.name() << " = " << o.gender << std::endl;
    os << o.studentID.name() << " = " << o.studentID << std::endl;
    os << o.iDCardNo.name() << " = " << o.iDCardNo << std::endl;
    os << o.iDMagCard.name() << " = " << o.iDMagCard << std::endl;
    os << o.nGrade.name() << " = " << o.nGrade << std::endl;
    os << o.nClass.name() << " = " << o.nClass << std::endl;
    os << o.nation.name() << " = " << o.nation << std::endl;
    os << o.faceFeature.name() << " = " << o.faceFeature << std::endl;
    os << o.faceImagePath.name() << " = " << o.faceImagePath << std::endl;
    os << o.campusMagcard.name() << " = " << o.campusMagcard << std::endl;
    os << o.timeStamp.name() << " = " << o.timeStamp << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType SandTableHistoryRecord::Own::Id("id_",A_field_type_integer,"SandTableHistoryRecord_");
const std::string SandTableHistoryRecord::type__("SandTableHistoryRecord");
const std::string SandTableHistoryRecord::table__("SandTableHistoryRecord_");
const std::string SandTableHistoryRecord::sequence__("SandTableHistoryRecord_seq");
const litesql::FieldType SandTableHistoryRecord::Id("id_",A_field_type_integer,table__);
const litesql::FieldType SandTableHistoryRecord::Type("type_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::UserID("userID_",A_field_type_bigint,table__);
const litesql::FieldType SandTableHistoryRecord::StartTime("startTime_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::StopTime("stopTime_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::TimeDuration("timeDuration_",A_field_type_bigint,table__);
const litesql::FieldType SandTableHistoryRecord::SceneType("sceneType_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::SandTableName("sandTableName_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::VisitorFile("visitorFile_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::VisitorSaid("visitorSaid_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::SandTableAnalysis("sandTableAnalysis_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::ImagePath1("imagePath1_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::ImagePath2("imagePath2_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::PalybackPath("palybackPath_",A_field_type_string,table__);
const litesql::FieldType SandTableHistoryRecord::IsUpload("isUpload_",A_field_type_boolean,table__);
void SandTableHistoryRecord::initValues() {
}
void SandTableHistoryRecord::defaults() {
    id = 0;
    userID = 0;
    timeDuration = 0;
    isUpload = 0;
}
SandTableHistoryRecord::SandTableHistoryRecord(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), userID(UserID), startTime(StartTime), stopTime(StopTime), timeDuration(TimeDuration), sceneType(SceneType), sandTableName(SandTableName), visitorFile(VisitorFile), visitorSaid(VisitorSaid), sandTableAnalysis(SandTableAnalysis), imagePath1(ImagePath1), imagePath2(ImagePath2), palybackPath(PalybackPath), isUpload(IsUpload) {
    defaults();
}
SandTableHistoryRecord::SandTableHistoryRecord(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), userID(UserID), startTime(StartTime), stopTime(StopTime), timeDuration(TimeDuration), sceneType(SceneType), sandTableName(SandTableName), visitorFile(VisitorFile), visitorSaid(VisitorSaid), sandTableAnalysis(SandTableAnalysis), imagePath1(ImagePath1), imagePath2(ImagePath2), palybackPath(PalybackPath), isUpload(IsUpload) {
    defaults();
    size_t size = (rec.size() > 15) ? 15 : rec.size();
    switch(size) {
    case 15: isUpload = convert<const std::string&, bool>(rec[14]);
        isUpload.setModified(false);
    case 14: palybackPath = convert<const std::string&, std::string>(rec[13]);
        palybackPath.setModified(false);
    case 13: imagePath2 = convert<const std::string&, std::string>(rec[12]);
        imagePath2.setModified(false);
    case 12: imagePath1 = convert<const std::string&, std::string>(rec[11]);
        imagePath1.setModified(false);
    case 11: sandTableAnalysis = convert<const std::string&, std::string>(rec[10]);
        sandTableAnalysis.setModified(false);
    case 10: visitorSaid = convert<const std::string&, std::string>(rec[9]);
        visitorSaid.setModified(false);
    case 9: visitorFile = convert<const std::string&, std::string>(rec[8]);
        visitorFile.setModified(false);
    case 8: sandTableName = convert<const std::string&, std::string>(rec[7]);
        sandTableName.setModified(false);
    case 7: sceneType = convert<const std::string&, std::string>(rec[6]);
        sceneType.setModified(false);
    case 6: timeDuration = convert<const std::string&, litesql::bigint>(rec[5]);
        timeDuration.setModified(false);
    case 5: stopTime = convert<const std::string&, std::string>(rec[4]);
        stopTime.setModified(false);
    case 4: startTime = convert<const std::string&, std::string>(rec[3]);
        startTime.setModified(false);
    case 3: userID = convert<const std::string&, litesql::bigint>(rec[2]);
        userID.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
SandTableHistoryRecord::SandTableHistoryRecord(const SandTableHistoryRecord& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), userID(obj.userID), startTime(obj.startTime), stopTime(obj.stopTime), timeDuration(obj.timeDuration), sceneType(obj.sceneType), sandTableName(obj.sandTableName), visitorFile(obj.visitorFile), visitorSaid(obj.visitorSaid), sandTableAnalysis(obj.sandTableAnalysis), imagePath1(obj.imagePath1), imagePath2(obj.imagePath2), palybackPath(obj.palybackPath), isUpload(obj.isUpload) {
}
const SandTableHistoryRecord& SandTableHistoryRecord::operator=(const SandTableHistoryRecord& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        userID = obj.userID;
        startTime = obj.startTime;
        stopTime = obj.stopTime;
        timeDuration = obj.timeDuration;
        sceneType = obj.sceneType;
        sandTableName = obj.sandTableName;
        visitorFile = obj.visitorFile;
        visitorSaid = obj.visitorSaid;
        sandTableAnalysis = obj.sandTableAnalysis;
        imagePath1 = obj.imagePath1;
        imagePath2 = obj.imagePath2;
        palybackPath = obj.palybackPath;
        isUpload = obj.isUpload;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string SandTableHistoryRecord::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(userID.name());
    values.push_back(userID);
    userID.setModified(false);
    fields.push_back(startTime.name());
    values.push_back(startTime);
    startTime.setModified(false);
    fields.push_back(stopTime.name());
    values.push_back(stopTime);
    stopTime.setModified(false);
    fields.push_back(timeDuration.name());
    values.push_back(timeDuration);
    timeDuration.setModified(false);
    fields.push_back(sceneType.name());
    values.push_back(sceneType);
    sceneType.setModified(false);
    fields.push_back(sandTableName.name());
    values.push_back(sandTableName);
    sandTableName.setModified(false);
    fields.push_back(visitorFile.name());
    values.push_back(visitorFile);
    visitorFile.setModified(false);
    fields.push_back(visitorSaid.name());
    values.push_back(visitorSaid);
    visitorSaid.setModified(false);
    fields.push_back(sandTableAnalysis.name());
    values.push_back(sandTableAnalysis);
    sandTableAnalysis.setModified(false);
    fields.push_back(imagePath1.name());
    values.push_back(imagePath1);
    imagePath1.setModified(false);
    fields.push_back(imagePath2.name());
    values.push_back(imagePath2);
    imagePath2.setModified(false);
    fields.push_back(palybackPath.name());
    values.push_back(palybackPath);
    palybackPath.setModified(false);
    fields.push_back(isUpload.name());
    values.push_back(isUpload);
    isUpload.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void SandTableHistoryRecord::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void SandTableHistoryRecord::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, userID);
    updateField(updates, table__, startTime);
    updateField(updates, table__, stopTime);
    updateField(updates, table__, timeDuration);
    updateField(updates, table__, sceneType);
    updateField(updates, table__, sandTableName);
    updateField(updates, table__, visitorFile);
    updateField(updates, table__, visitorSaid);
    updateField(updates, table__, sandTableAnalysis);
    updateField(updates, table__, imagePath1);
    updateField(updates, table__, imagePath2);
    updateField(updates, table__, palybackPath);
    updateField(updates, table__, isUpload);
}
void SandTableHistoryRecord::addIDUpdates(Updates& updates) {
}
void SandTableHistoryRecord::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(UserID);
    ftypes.push_back(StartTime);
    ftypes.push_back(StopTime);
    ftypes.push_back(TimeDuration);
    ftypes.push_back(SceneType);
    ftypes.push_back(SandTableName);
    ftypes.push_back(VisitorFile);
    ftypes.push_back(VisitorSaid);
    ftypes.push_back(SandTableAnalysis);
    ftypes.push_back(ImagePath1);
    ftypes.push_back(ImagePath2);
    ftypes.push_back(PalybackPath);
    ftypes.push_back(IsUpload);
}
void SandTableHistoryRecord::delRecord() {
    deleteFromTable(table__, id);
}
void SandTableHistoryRecord::delRelations() {
}
void SandTableHistoryRecord::update() {
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
void SandTableHistoryRecord::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<SandTableHistoryRecord> p(upcastCopy());
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
bool SandTableHistoryRecord::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<SandTableHistoryRecord> SandTableHistoryRecord::upcast() const {
    return unique_ptr<SandTableHistoryRecord>(new SandTableHistoryRecord(*this));
}
std::unique_ptr<SandTableHistoryRecord> SandTableHistoryRecord::upcastCopy() const {
    SandTableHistoryRecord* np = new SandTableHistoryRecord(*this);
    np->id = id;
    np->type = type;
    np->userID = userID;
    np->startTime = startTime;
    np->stopTime = stopTime;
    np->timeDuration = timeDuration;
    np->sceneType = sceneType;
    np->sandTableName = sandTableName;
    np->visitorFile = visitorFile;
    np->visitorSaid = visitorSaid;
    np->sandTableAnalysis = sandTableAnalysis;
    np->imagePath1 = imagePath1;
    np->imagePath2 = imagePath2;
    np->palybackPath = palybackPath;
    np->isUpload = isUpload;
    np->inDatabase = inDatabase;
    return unique_ptr<SandTableHistoryRecord>(np);
}
std::ostream & operator<<(std::ostream& os, SandTableHistoryRecord o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.userID.name() << " = " << o.userID << std::endl;
    os << o.startTime.name() << " = " << o.startTime << std::endl;
    os << o.stopTime.name() << " = " << o.stopTime << std::endl;
    os << o.timeDuration.name() << " = " << o.timeDuration << std::endl;
    os << o.sceneType.name() << " = " << o.sceneType << std::endl;
    os << o.sandTableName.name() << " = " << o.sandTableName << std::endl;
    os << o.visitorFile.name() << " = " << o.visitorFile << std::endl;
    os << o.visitorSaid.name() << " = " << o.visitorSaid << std::endl;
    os << o.sandTableAnalysis.name() << " = " << o.sandTableAnalysis << std::endl;
    os << o.imagePath1.name() << " = " << o.imagePath1 << std::endl;
    os << o.imagePath2.name() << " = " << o.imagePath2 << std::endl;
    os << o.palybackPath.name() << " = " << o.palybackPath << std::endl;
    os << o.isUpload.name() << " = " << o.isUpload << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType SandToySets::Own::Id("id_",A_field_type_integer,"SandToySets_");
const std::string SandToySets::type__("SandToySets");
const std::string SandToySets::table__("SandToySets_");
const std::string SandToySets::sequence__("SandToySets_seq");
const litesql::FieldType SandToySets::Id("id_",A_field_type_integer,table__);
const litesql::FieldType SandToySets::Type("type_",A_field_type_string,table__);
const litesql::FieldType SandToySets::GameID("gameID_",A_field_type_bigint,table__);
const litesql::FieldType SandToySets::Order("order_",A_field_type_bigint,table__);
const litesql::FieldType SandToySets::ToyID("toyID_",A_field_type_bigint,table__);
const litesql::FieldType SandToySets::ToyCategory("toyCategory_",A_field_type_integer,table__);
const litesql::FieldType SandToySets::ToyName("toyName_",A_field_type_string,table__);
const litesql::FieldType SandToySets::SymbolicSignificance("symbolicSignificance_",A_field_type_string,table__);
const litesql::FieldType SandToySets::IsColdColor("isColdColor_",A_field_type_boolean,table__);
const litesql::FieldType SandToySets::IsDeleted("isDeleted_",A_field_type_boolean,table__);
void SandToySets::initValues() {
}
void SandToySets::defaults() {
    id = 0;
    gameID = 0;
    order = 0;
    toyID = 0;
    toyCategory = 0;
    isColdColor = 0;
    isDeleted = 0;
}
SandToySets::SandToySets(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), gameID(GameID), order(Order), toyID(ToyID), toyCategory(ToyCategory), toyName(ToyName), symbolicSignificance(SymbolicSignificance), isColdColor(IsColdColor), isDeleted(IsDeleted) {
    defaults();
}
SandToySets::SandToySets(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), gameID(GameID), order(Order), toyID(ToyID), toyCategory(ToyCategory), toyName(ToyName), symbolicSignificance(SymbolicSignificance), isColdColor(IsColdColor), isDeleted(IsDeleted) {
    defaults();
    size_t size = (rec.size() > 10) ? 10 : rec.size();
    switch(size) {
    case 10: isDeleted = convert<const std::string&, bool>(rec[9]);
        isDeleted.setModified(false);
    case 9: isColdColor = convert<const std::string&, bool>(rec[8]);
        isColdColor.setModified(false);
    case 8: symbolicSignificance = convert<const std::string&, std::string>(rec[7]);
        symbolicSignificance.setModified(false);
    case 7: toyName = convert<const std::string&, std::string>(rec[6]);
        toyName.setModified(false);
    case 6: toyCategory = convert<const std::string&, int>(rec[5]);
        toyCategory.setModified(false);
    case 5: toyID = convert<const std::string&, litesql::bigint>(rec[4]);
        toyID.setModified(false);
    case 4: order = convert<const std::string&, litesql::bigint>(rec[3]);
        order.setModified(false);
    case 3: gameID = convert<const std::string&, litesql::bigint>(rec[2]);
        gameID.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
SandToySets::SandToySets(const SandToySets& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), gameID(obj.gameID), order(obj.order), toyID(obj.toyID), toyCategory(obj.toyCategory), toyName(obj.toyName), symbolicSignificance(obj.symbolicSignificance), isColdColor(obj.isColdColor), isDeleted(obj.isDeleted) {
}
const SandToySets& SandToySets::operator=(const SandToySets& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        gameID = obj.gameID;
        order = obj.order;
        toyID = obj.toyID;
        toyCategory = obj.toyCategory;
        toyName = obj.toyName;
        symbolicSignificance = obj.symbolicSignificance;
        isColdColor = obj.isColdColor;
        isDeleted = obj.isDeleted;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string SandToySets::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(gameID.name());
    values.push_back(gameID);
    gameID.setModified(false);
    fields.push_back(order.name());
    values.push_back(order);
    order.setModified(false);
    fields.push_back(toyID.name());
    values.push_back(toyID);
    toyID.setModified(false);
    fields.push_back(toyCategory.name());
    values.push_back(toyCategory);
    toyCategory.setModified(false);
    fields.push_back(toyName.name());
    values.push_back(toyName);
    toyName.setModified(false);
    fields.push_back(symbolicSignificance.name());
    values.push_back(symbolicSignificance);
    symbolicSignificance.setModified(false);
    fields.push_back(isColdColor.name());
    values.push_back(isColdColor);
    isColdColor.setModified(false);
    fields.push_back(isDeleted.name());
    values.push_back(isDeleted);
    isDeleted.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void SandToySets::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void SandToySets::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, gameID);
    updateField(updates, table__, order);
    updateField(updates, table__, toyID);
    updateField(updates, table__, toyCategory);
    updateField(updates, table__, toyName);
    updateField(updates, table__, symbolicSignificance);
    updateField(updates, table__, isColdColor);
    updateField(updates, table__, isDeleted);
}
void SandToySets::addIDUpdates(Updates& updates) {
}
void SandToySets::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(GameID);
    ftypes.push_back(Order);
    ftypes.push_back(ToyID);
    ftypes.push_back(ToyCategory);
    ftypes.push_back(ToyName);
    ftypes.push_back(SymbolicSignificance);
    ftypes.push_back(IsColdColor);
    ftypes.push_back(IsDeleted);
}
void SandToySets::delRecord() {
    deleteFromTable(table__, id);
}
void SandToySets::delRelations() {
}
void SandToySets::update() {
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
void SandToySets::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<SandToySets> p(upcastCopy());
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
bool SandToySets::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<SandToySets> SandToySets::upcast() const {
    return unique_ptr<SandToySets>(new SandToySets(*this));
}
std::unique_ptr<SandToySets> SandToySets::upcastCopy() const {
    SandToySets* np = new SandToySets(*this);
    np->id = id;
    np->type = type;
    np->gameID = gameID;
    np->order = order;
    np->toyID = toyID;
    np->toyCategory = toyCategory;
    np->toyName = toyName;
    np->symbolicSignificance = symbolicSignificance;
    np->isColdColor = isColdColor;
    np->isDeleted = isDeleted;
    np->inDatabase = inDatabase;
    return unique_ptr<SandToySets>(np);
}
std::ostream & operator<<(std::ostream& os, SandToySets o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.gameID.name() << " = " << o.gameID << std::endl;
    os << o.order.name() << " = " << o.order << std::endl;
    os << o.toyID.name() << " = " << o.toyID << std::endl;
    os << o.toyCategory.name() << " = " << o.toyCategory << std::endl;
    os << o.toyName.name() << " = " << o.toyName << std::endl;
    os << o.symbolicSignificance.name() << " = " << o.symbolicSignificance << std::endl;
    os << o.isColdColor.name() << " = " << o.isColdColor << std::endl;
    os << o.isDeleted.name() << " = " << o.isDeleted << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
const litesql::FieldType classInfo::Own::Id("id_",A_field_type_integer,"classInfo_");
const std::string classInfo::type__("classInfo");
const std::string classInfo::table__("classInfo_");
const std::string classInfo::sequence__("classInfo_seq");
const litesql::FieldType classInfo::Id("id_",A_field_type_integer,table__);
const litesql::FieldType classInfo::Type("type_",A_field_type_string,table__);
const litesql::FieldType classInfo::ClassID("classID_",A_field_type_integer,table__);
const litesql::FieldType classInfo::ClassName("className_",A_field_type_string,table__);
void classInfo::initValues() {
}
void classInfo::defaults() {
    id = 0;
    classID = 0;
}
classInfo::classInfo(const litesql::Database& db)
     : litesql::Persistent(db), id(Id), type(Type), classID(ClassID), className(ClassName) {
    defaults();
}
classInfo::classInfo(const litesql::Database& db, const litesql::Record& rec)
     : litesql::Persistent(db, rec), id(Id), type(Type), classID(ClassID), className(ClassName) {
    defaults();
    size_t size = (rec.size() > 4) ? 4 : rec.size();
    switch(size) {
    case 4: className = convert<const std::string&, std::string>(rec[3]);
        className.setModified(false);
    case 3: classID = convert<const std::string&, int>(rec[2]);
        classID.setModified(false);
    case 2: type = convert<const std::string&, std::string>(rec[1]);
        type.setModified(false);
    case 1: id = convert<const std::string&, int>(rec[0]);
        id.setModified(false);
    }
}
classInfo::classInfo(const classInfo& obj)
     : litesql::Persistent(obj), id(obj.id), type(obj.type), classID(obj.classID), className(obj.className) {
}
const classInfo& classInfo::operator=(const classInfo& obj) {
    if (this != &obj) {
        id = obj.id;
        type = obj.type;
        classID = obj.classID;
        className = obj.className;
    }
    litesql::Persistent::operator=(obj);
    return *this;
}
std::string classInfo::insert(litesql::Record& tables, litesql::Records& fieldRecs, litesql::Records& valueRecs) {
    tables.push_back(table__);
    litesql::Record fields;
    litesql::Record values;
    fields.push_back(id.name());
    values.push_back(id);
    id.setModified(false);
    fields.push_back(type.name());
    values.push_back(type);
    type.setModified(false);
    fields.push_back(classID.name());
    values.push_back(classID);
    classID.setModified(false);
    fields.push_back(className.name());
    values.push_back(className);
    className.setModified(false);
    fieldRecs.push_back(fields);
    valueRecs.push_back(values);
    return litesql::Persistent::insert(tables, fieldRecs, valueRecs, sequence__);
}
void classInfo::create() {
    litesql::Record tables;
    litesql::Records fieldRecs;
    litesql::Records valueRecs;
    type = type__;
    std::string newID = insert(tables, fieldRecs, valueRecs);
    if (id == 0)
        id = newID;
}
void classInfo::addUpdates(Updates& updates) {
    prepareUpdate(updates, table__);
    updateField(updates, table__, id);
    updateField(updates, table__, type);
    updateField(updates, table__, classID);
    updateField(updates, table__, className);
}
void classInfo::addIDUpdates(Updates& updates) {
}
void classInfo::getFieldTypes(std::vector<litesql::FieldType>& ftypes) {
    ftypes.push_back(Id);
    ftypes.push_back(Type);
    ftypes.push_back(ClassID);
    ftypes.push_back(ClassName);
}
void classInfo::delRecord() {
    deleteFromTable(table__, id);
}
void classInfo::delRelations() {
}
void classInfo::update() {
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
void classInfo::del() {
    if (!typeIsCorrect()) {
        std::unique_ptr<classInfo> p(upcastCopy());
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
bool classInfo::typeIsCorrect() const {
    return type == type__;
}
std::unique_ptr<classInfo> classInfo::upcast() const {
    return unique_ptr<classInfo>(new classInfo(*this));
}
std::unique_ptr<classInfo> classInfo::upcastCopy() const {
    classInfo* np = new classInfo(*this);
    np->id = id;
    np->type = type;
    np->classID = classID;
    np->className = className;
    np->inDatabase = inDatabase;
    return unique_ptr<classInfo>(np);
}
std::ostream & operator<<(std::ostream& os, classInfo o) {
    os << "-------------------------------------" << std::endl;
    os << o.id.name() << " = " << o.id << std::endl;
    os << o.type.name() << " = " << o.type << std::endl;
    os << o.classID.name() << " = " << o.classID << std::endl;
    os << o.className.name() << " = " << o.className << std::endl;
    os << "-------------------------------------" << std::endl;
    return os;
}
EPS100Database::EPS100Database(std::string backendType, std::string connInfo)
     : litesql::Database(backendType, connInfo) {
    initialize();
}
std::vector<litesql::Database::SchemaItem> EPS100Database::getSchema() const {
    vector<Database::SchemaItem> res;
    string TEXT = backend->getSQLType(A_field_type_string);
    string rowIdType = backend->getRowIDType();
    res.push_back(Database::SchemaItem("schema_","table","CREATE TABLE schema_ (name_ "+TEXT+", type_ "+TEXT+", sql_ "+TEXT+")"));
    if (backend->supportsSequences()) {
        res.push_back(Database::SchemaItem("ConfigVersion_seq","sequence",backend->getCreateSequenceSQL("ConfigVersion_seq")));
        res.push_back(Database::SchemaItem("DataSyncTime_seq","sequence",backend->getCreateSequenceSQL("DataSyncTime_seq")));
        res.push_back(Database::SchemaItem("UserIdentityInfo_seq","sequence",backend->getCreateSequenceSQL("UserIdentityInfo_seq")));
        res.push_back(Database::SchemaItem("SandTableHistoryRecord_seq","sequence",backend->getCreateSequenceSQL("SandTableHistoryRecord_seq")));
        res.push_back(Database::SchemaItem("SandToySets_seq","sequence",backend->getCreateSequenceSQL("SandToySets_seq")));
        res.push_back(Database::SchemaItem("classInfo_seq","sequence",backend->getCreateSequenceSQL("classInfo_seq")));
    }
    res.push_back(Database::SchemaItem("ConfigVersion_","table","CREATE TABLE ConfigVersion_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",cfgVersion_ " + backend->getSQLType(A_field_type_string,"") + "" +")"));
    res.push_back(Database::SchemaItem("DataSyncTime_","table","CREATE TABLE DataSyncTime_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",lastSyncTime_ " + backend->getSQLType(A_field_type_string,"") + "" +")"));
    res.push_back(Database::SchemaItem("UserIdentityInfo_","table","CREATE TABLE UserIdentityInfo_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",codeUniqueID_ " + backend->getSQLType(A_field_type_string,"") + "" +",roleType_ " + backend->getSQLType(A_field_type_integer,"") + "" +",name_ " + backend->getSQLType(A_field_type_string,"") + "" +",brithday_ " + backend->getSQLType(A_field_type_string,"") + "" +",gender_ " + backend->getSQLType(A_field_type_integer,"") + "" +",studentID_ " + backend->getSQLType(A_field_type_string,"") + "" +",iDCardNo_ " + backend->getSQLType(A_field_type_string,"") + "" +",iDMagCard_ " + backend->getSQLType(A_field_type_string,"") + "" +",nGrade_ " + backend->getSQLType(A_field_type_integer,"") + "" +",nClass_ " + backend->getSQLType(A_field_type_integer,"") + "" +",nation_ " + backend->getSQLType(A_field_type_string,"") + "" +",faceFeature_ " + backend->getSQLType(A_field_type_string,"") + "" +",faceImagePath_ " + backend->getSQLType(A_field_type_string,"") + "" +",campusMagcard_ " + backend->getSQLType(A_field_type_string,"") + "" +",timeStamp_ " + backend->getSQLType(A_field_type_string,"") + "" +")"));
    res.push_back(Database::SchemaItem("SandTableHistoryRecord_","table","CREATE TABLE SandTableHistoryRecord_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",userID_ " + backend->getSQLType(A_field_type_bigint,"") + "" +",startTime_ " + backend->getSQLType(A_field_type_string,"") + "" +",stopTime_ " + backend->getSQLType(A_field_type_string,"") + "" +",timeDuration_ " + backend->getSQLType(A_field_type_bigint,"") + "" +",sceneType_ " + backend->getSQLType(A_field_type_string,"") + "" +",sandTableName_ " + backend->getSQLType(A_field_type_string,"") + "" +",visitorFile_ " + backend->getSQLType(A_field_type_string,"") + "" +",visitorSaid_ " + backend->getSQLType(A_field_type_string,"") + "" +",sandTableAnalysis_ " + backend->getSQLType(A_field_type_string,"") + "" +",imagePath1_ " + backend->getSQLType(A_field_type_string,"") + "" +",imagePath2_ " + backend->getSQLType(A_field_type_string,"") + "" +",palybackPath_ " + backend->getSQLType(A_field_type_string,"") + "" +",isUpload_ " + backend->getSQLType(A_field_type_boolean,"") + "" +")"));
    res.push_back(Database::SchemaItem("SandToySets_","table","CREATE TABLE SandToySets_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",gameID_ " + backend->getSQLType(A_field_type_bigint,"") + "" +",order_ " + backend->getSQLType(A_field_type_bigint,"") + "" +",toyID_ " + backend->getSQLType(A_field_type_bigint,"") + "" +",toyCategory_ " + backend->getSQLType(A_field_type_integer,"") + "" +",toyName_ " + backend->getSQLType(A_field_type_string,"") + "" +",symbolicSignificance_ " + backend->getSQLType(A_field_type_string,"") + "" +",isColdColor_ " + backend->getSQLType(A_field_type_boolean,"") + "" +",isDeleted_ " + backend->getSQLType(A_field_type_boolean,"") + "" +")"));
    res.push_back(Database::SchemaItem("classInfo_","table","CREATE TABLE classInfo_ (id_ " + rowIdType + ",type_ " + backend->getSQLType(A_field_type_string,"") + "" +",classID_ " + backend->getSQLType(A_field_type_integer,"") + "" +",className_ " + backend->getSQLType(A_field_type_string,"") + "" +")"));
    res.push_back(Database::SchemaItem("ConfigVersion_id_idx","index","CREATE INDEX ConfigVersion_id_idx ON ConfigVersion_ (id_)"));
    res.push_back(Database::SchemaItem("DataSyncTime_id_idx","index","CREATE INDEX DataSyncTime_id_idx ON DataSyncTime_ (id_)"));
    res.push_back(Database::SchemaItem("UserIdentityInfo_id_idx","index","CREATE INDEX UserIdentityInfo_id_idx ON UserIdentityInfo_ (id_)"));
    res.push_back(Database::SchemaItem("SandTableHistoryRecord_id_idx","index","CREATE INDEX SandTableHistoryRecord_id_idx ON SandTableHistoryRecord_ (id_)"));
    res.push_back(Database::SchemaItem("SandToySets_id_idx","index","CREATE INDEX SandToySets_id_idx ON SandToySets_ (id_)"));
    res.push_back(Database::SchemaItem("classInfo_id_idx","index","CREATE INDEX classInfo_id_idx ON classInfo_ (id_)"));
    return res;
}
void EPS100Database::initialize() {
    static bool initialized = false;
    if (initialized)
        return;
    initialized = true;
    UserIdentityInfo::initValues();
}
}
