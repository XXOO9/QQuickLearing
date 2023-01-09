#ifndef eps100database_hpp
#define eps100database_hpp
#include "litesql.hpp"
namespace EPSDatabase {
class ConfigVersion;
class DataSyncTime;
class UserIdentityInfo;
class SandTableHistoryRecord;
class SandToySets;
class classInfo;
class ConfigVersion : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType CfgVersion;
    litesql::Field<std::string> cfgVersion;
    static void initValues();
protected:
    void defaults();
public:
    ConfigVersion(const litesql::Database& db);
    ConfigVersion(const litesql::Database& db, const litesql::Record& rec);
    ConfigVersion(const ConfigVersion& obj);
    const ConfigVersion& operator=(const ConfigVersion& obj);
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
    std::unique_ptr<ConfigVersion> upcast() const;
    std::unique_ptr<ConfigVersion> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, ConfigVersion o);
class DataSyncTime : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType LastSyncTime;
    litesql::Field<std::string> lastSyncTime;
    static void initValues();
protected:
    void defaults();
public:
    DataSyncTime(const litesql::Database& db);
    DataSyncTime(const litesql::Database& db, const litesql::Record& rec);
    DataSyncTime(const DataSyncTime& obj);
    const DataSyncTime& operator=(const DataSyncTime& obj);
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
    std::unique_ptr<DataSyncTime> upcast() const;
    std::unique_ptr<DataSyncTime> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, DataSyncTime o);
class UserIdentityInfo : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    class RoleTypeType : public litesql::FieldType {
    public:
        static const int UNKNOW;
        static const int GUEST;
        static const int NORMAL;
        static const int ADMIN;
        RoleTypeType(const std::string& n, AT_field_type t, const std::string& tbl, const litesql::FieldType::Values& vals=Values());
    };
    class RoleType {
    public:
        static const int UNKNOW;
        static const int GUEST;
        static const int NORMAL;
        static const int ADMIN;
    };
    class GenderType : public litesql::FieldType {
    public:
        static const int MALE;
        static const int FEMALE;
        GenderType(const std::string& n, AT_field_type t, const std::string& tbl, const litesql::FieldType::Values& vals=Values());
    };
    class Gender {
    public:
        static const int MALE;
        static const int FEMALE;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType CodeUniqueID;
    litesql::Field<std::string> codeUniqueID;
protected:
    static std::vector < std::pair< std::string, std::string > > roleType_values;
public:
    static const litesql::FieldType RoleType;
    litesql::Field<int> roleType;
    static const litesql::FieldType Name;
    litesql::Field<std::string> name;
    static const litesql::FieldType Brithday;
    litesql::Field<std::string> brithday;
protected:
    static std::vector < std::pair< std::string, std::string > > gender_values;
public:
    static const litesql::FieldType Gender;
    litesql::Field<int> gender;
    static const litesql::FieldType StudentID;
    litesql::Field<std::string> studentID;
    static const litesql::FieldType IDCardNo;
    litesql::Field<std::string> iDCardNo;
    static const litesql::FieldType IDMagCard;
    litesql::Field<std::string> iDMagCard;
    static const litesql::FieldType NGrade;
    litesql::Field<int> nGrade;
    static const litesql::FieldType NClass;
    litesql::Field<int> nClass;
    static const litesql::FieldType Nation;
    litesql::Field<std::string> nation;
    static const litesql::FieldType FaceFeature;
    litesql::Field<std::string> faceFeature;
    static const litesql::FieldType FaceImagePath;
    litesql::Field<std::string> faceImagePath;
    static const litesql::FieldType CampusMagcard;
    litesql::Field<std::string> campusMagcard;
    static const litesql::FieldType TimeStamp;
    litesql::Field<std::string> timeStamp;
    static void initValues();
protected:
    void defaults();
public:
    UserIdentityInfo(const litesql::Database& db);
    UserIdentityInfo(const litesql::Database& db, const litesql::Record& rec);
    UserIdentityInfo(const UserIdentityInfo& obj);
    const UserIdentityInfo& operator=(const UserIdentityInfo& obj);
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
    std::unique_ptr<UserIdentityInfo> upcast() const;
    std::unique_ptr<UserIdentityInfo> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, UserIdentityInfo o);
class SandTableHistoryRecord : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType UserID;
    litesql::Field<litesql::bigint> userID;
    static const litesql::FieldType StartTime;
    litesql::Field<std::string> startTime;
    static const litesql::FieldType StopTime;
    litesql::Field<std::string> stopTime;
    static const litesql::FieldType TimeDuration;
    litesql::Field<litesql::bigint> timeDuration;
    static const litesql::FieldType SceneType;
    litesql::Field<std::string> sceneType;
    static const litesql::FieldType SandTableName;
    litesql::Field<std::string> sandTableName;
    static const litesql::FieldType VisitorFile;
    litesql::Field<std::string> visitorFile;
    static const litesql::FieldType VisitorSaid;
    litesql::Field<std::string> visitorSaid;
    static const litesql::FieldType SandTableAnalysis;
    litesql::Field<std::string> sandTableAnalysis;
    static const litesql::FieldType ImagePath1;
    litesql::Field<std::string> imagePath1;
    static const litesql::FieldType ImagePath2;
    litesql::Field<std::string> imagePath2;
    static const litesql::FieldType PalybackPath;
    litesql::Field<std::string> palybackPath;
    static const litesql::FieldType IsUpload;
    litesql::Field<bool> isUpload;
    static void initValues();
protected:
    void defaults();
public:
    SandTableHistoryRecord(const litesql::Database& db);
    SandTableHistoryRecord(const litesql::Database& db, const litesql::Record& rec);
    SandTableHistoryRecord(const SandTableHistoryRecord& obj);
    const SandTableHistoryRecord& operator=(const SandTableHistoryRecord& obj);
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
    std::unique_ptr<SandTableHistoryRecord> upcast() const;
    std::unique_ptr<SandTableHistoryRecord> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, SandTableHistoryRecord o);
class SandToySets : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType GameID;
    litesql::Field<litesql::bigint> gameID;
    static const litesql::FieldType Order;
    litesql::Field<litesql::bigint> order;
    static const litesql::FieldType ToyID;
    litesql::Field<litesql::bigint> toyID;
    static const litesql::FieldType ToyCategory;
    litesql::Field<int> toyCategory;
    static const litesql::FieldType ToyName;
    litesql::Field<std::string> toyName;
    static const litesql::FieldType SymbolicSignificance;
    litesql::Field<std::string> symbolicSignificance;
    static const litesql::FieldType IsColdColor;
    litesql::Field<bool> isColdColor;
    static const litesql::FieldType IsDeleted;
    litesql::Field<bool> isDeleted;
    static void initValues();
protected:
    void defaults();
public:
    SandToySets(const litesql::Database& db);
    SandToySets(const litesql::Database& db, const litesql::Record& rec);
    SandToySets(const SandToySets& obj);
    const SandToySets& operator=(const SandToySets& obj);
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
    std::unique_ptr<SandToySets> upcast() const;
    std::unique_ptr<SandToySets> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, SandToySets o);
class classInfo : public litesql::Persistent {
public:
    class Own {
    public:
        static const litesql::FieldType Id;
    };
    static const std::string type__;
    static const std::string table__;
    static const std::string sequence__;
    static const litesql::FieldType Id;
    litesql::Field<int> id;
    static const litesql::FieldType Type;
    litesql::Field<std::string> type;
    static const litesql::FieldType ClassID;
    litesql::Field<int> classID;
    static const litesql::FieldType ClassName;
    litesql::Field<std::string> className;
    static void initValues();
protected:
    void defaults();
public:
    classInfo(const litesql::Database& db);
    classInfo(const litesql::Database& db, const litesql::Record& rec);
    classInfo(const classInfo& obj);
    const classInfo& operator=(const classInfo& obj);
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
    std::unique_ptr<classInfo> upcast() const;
    std::unique_ptr<classInfo> upcastCopy() const;
};
std::ostream & operator<<(std::ostream& os, classInfo o);
class EPS100Database : public litesql::Database {
public:
    EPS100Database(std::string backendType, std::string connInfo);
protected:
    virtual std::vector<litesql::Database::SchemaItem> getSchema() const;
    static void initialize();
};
}
#endif
