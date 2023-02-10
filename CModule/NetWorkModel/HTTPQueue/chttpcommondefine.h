#ifndef CHTTPCOMMONDEFINE_H
#define CHTTPCOMMONDEFINE_H

namespace HeaderContentKeys {
const QByteArray contentType              = "Content-type";
const QByteArray contentTypeJson          = "application/json";
const QByteArray contentTypeUrlenCoded    = "application/x-www-form-urlencoded";
const QByteArray contentTypeAuthorization = "Authorization";
const QByteArray contentTypeBear          = "Bearer ";
}

namespace RequestHeartBeatKeys {

}

enum RequestType{
    GET = 0,
    POST,
};

#endif // CHTTPCOMMONDEFINE_H
