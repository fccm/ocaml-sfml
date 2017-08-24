/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2012 Florent Monnier <monnier.florent(_)gmail.com>
 *
 * This software is provided 'as-is', without any express or implied warranty.
 * In no event will the authors be held liable for any damages arising from the
 * use of this software.
 *
 * Permission is granted to anyone to use this software for any purpose,
 * including commercial applications, and to alter it and redistribute it
 * freely, subject to the following restrictions:
 *
 * 1. The origin of this software must not be misrepresented;
 *    you must not claim that you wrote the original software.
 *    If you use this software in a product, an acknowledgment
 *    in the product documentation would be appreciated but is not required.
 *
 * 2. Altered source versions must be plainly marked as such,
 *    and must not be misrepresented as being the original software.
 *
 * 3. This notice may not be removed or altered from any source distribution.
 */

#include <SFML/Network/Ftp.hpp>

#include "sf_caml_incs.hpp"
#include "sf_caml_conv.hpp"
#include "SFIpAddress_stub.hpp"
#include "SFTime_stub.hpp"


static const sf::Ftp::Response::Status ml_table_sfFtpStatus[] = {
    sf::Ftp::Response::RestartMarkerReply,
    sf::Ftp::Response::ServiceReadySoon,
    sf::Ftp::Response::DataConnectionAlreadyOpened,
    sf::Ftp::Response::OpeningDataConnection,
    sf::Ftp::Response::Ok,
    sf::Ftp::Response::PointlessCommand,
    sf::Ftp::Response::SystemStatus,
    sf::Ftp::Response::DirectoryStatus,
    sf::Ftp::Response::FileStatus,
    sf::Ftp::Response::HelpMessage,
    sf::Ftp::Response::SystemType,
    sf::Ftp::Response::ServiceReady,
    sf::Ftp::Response::ClosingConnection,
    sf::Ftp::Response::DataConnectionOpened,
    sf::Ftp::Response::ClosingDataConnection,
    sf::Ftp::Response::EnteringPassiveMode,
    sf::Ftp::Response::LoggedIn,
    sf::Ftp::Response::FileActionOk,
    sf::Ftp::Response::DirectoryOk,
    sf::Ftp::Response::NeedPassword,
    sf::Ftp::Response::NeedAccountToLogIn,
    sf::Ftp::Response::NeedInformation,
    sf::Ftp::Response::ServiceUnavailable,
    sf::Ftp::Response::DataConnectionUnavailable,
    sf::Ftp::Response::TransferAborted,
    sf::Ftp::Response::FileActionAborted,
    sf::Ftp::Response::LocalError,
    sf::Ftp::Response::InsufficientStorageSpace,
    sf::Ftp::Response::CommandUnknown,
    sf::Ftp::Response::ParametersUnknown,
    sf::Ftp::Response::CommandNotImplemented,
    sf::Ftp::Response::BadCommandSequence,
    sf::Ftp::Response::ParameterNotImplemented,
    sf::Ftp::Response::NotLoggedIn,
    sf::Ftp::Response::NeedAccountToStore,
    sf::Ftp::Response::FileUnavailable,
    sf::Ftp::Response::PageTypeUnknown,
    sf::Ftp::Response::NotEnoughMemory,
    sf::Ftp::Response::FilenameNotAllowed,
    sf::Ftp::Response::InvalidResponse,
    sf::Ftp::Response::ConnectionFailed,
    sf::Ftp::Response::ConnectionClosed,
    sf::Ftp::Response::InvalidFile,
};

#define SfFtpStatus_val(v) \
    (ml_table_sfFtpStatus[Long_val(v)])



value
Val_sfFtpStatus(sf::Ftp::Response::Status e)
{
    switch (e)
    {
      case sf::Ftp::Response::RestartMarkerReply:          return Val_long(0);
      case sf::Ftp::Response::ServiceReadySoon:            return Val_long(1);
      case sf::Ftp::Response::DataConnectionAlreadyOpened: return Val_long(2);
      case sf::Ftp::Response::OpeningDataConnection:       return Val_long(3);
      case sf::Ftp::Response::Ok:                          return Val_long(4);
      case sf::Ftp::Response::PointlessCommand:            return Val_long(5);
      case sf::Ftp::Response::SystemStatus:                return Val_long(6);
      case sf::Ftp::Response::DirectoryStatus:             return Val_long(7);
      case sf::Ftp::Response::FileStatus:                  return Val_long(8);
      case sf::Ftp::Response::HelpMessage:                 return Val_long(9);
      case sf::Ftp::Response::SystemType:                  return Val_long(10);
      case sf::Ftp::Response::ServiceReady:                return Val_long(11);
      case sf::Ftp::Response::ClosingConnection:           return Val_long(12);
      case sf::Ftp::Response::DataConnectionOpened:        return Val_long(13);
      case sf::Ftp::Response::ClosingDataConnection:       return Val_long(14);
      case sf::Ftp::Response::EnteringPassiveMode:         return Val_long(15);
      case sf::Ftp::Response::LoggedIn:                    return Val_long(16);
      case sf::Ftp::Response::FileActionOk:                return Val_long(17);
      case sf::Ftp::Response::DirectoryOk:                 return Val_long(18);
      case sf::Ftp::Response::NeedPassword:                return Val_long(19);
      case sf::Ftp::Response::NeedAccountToLogIn:          return Val_long(20);
      case sf::Ftp::Response::NeedInformation:             return Val_long(21);
      case sf::Ftp::Response::ServiceUnavailable:          return Val_long(22);
      case sf::Ftp::Response::DataConnectionUnavailable:   return Val_long(23);
      case sf::Ftp::Response::TransferAborted:             return Val_long(24);
      case sf::Ftp::Response::FileActionAborted:           return Val_long(25);
      case sf::Ftp::Response::LocalError:                  return Val_long(26);
      case sf::Ftp::Response::InsufficientStorageSpace:    return Val_long(27);
      case sf::Ftp::Response::CommandUnknown:              return Val_long(28);
      case sf::Ftp::Response::ParametersUnknown:           return Val_long(29);
      case sf::Ftp::Response::CommandNotImplemented:       return Val_long(30);
      case sf::Ftp::Response::BadCommandSequence:          return Val_long(31);
      case sf::Ftp::Response::ParameterNotImplemented:     return Val_long(32);
      case sf::Ftp::Response::NotLoggedIn:                 return Val_long(33);
      case sf::Ftp::Response::NeedAccountToStore:          return Val_long(34);
      case sf::Ftp::Response::FileUnavailable:             return Val_long(35);
      case sf::Ftp::Response::PageTypeUnknown:             return Val_long(36);
      case sf::Ftp::Response::NotEnoughMemory:             return Val_long(37);
      case sf::Ftp::Response::FilenameNotAllowed:          return Val_long(38);
      case sf::Ftp::Response::InvalidResponse:             return Val_long(39);
      case sf::Ftp::Response::ConnectionFailed:            return Val_long(40);
      case sf::Ftp::Response::ConnectionClosed:            return Val_long(41);
      case sf::Ftp::Response::InvalidFile:                 return Val_long(42);

      default: caml_failwith("SFFtp.status");
    }
    caml_failwith("SFFtp.status");
}


static const sf::Ftp::TransferMode ml_table_sfFtpTransferMode[] = {
    sf::Ftp::Binary,
    sf::Ftp::Ascii,
    sf::Ftp::Ebcdic,
};

#define SfFtpTransferMode_val(v) \
    (ml_table_sfFtpTransferMode[Long_val(v)])

value
Val_sfFtpTransferMode(sf::Ftp::TransferMode e)
{
    switch (e)
    {
        case sf::Ftp::Binary:  return Val_long(0);
        case sf::Ftp::Ascii:   return Val_long(1);
        case sf::Ftp::Ebcdic:  return Val_long(2);

        default: caml_failwith("SFFtp.transferMode");
    }
    caml_failwith("SFFtp.transferMode");
}

#define Val_sfFtp(ftp) ((value)(ftp))
#define SfFtp_val(ftp) ((sf::Ftp *)(ftp))

#define Val_sfFtpResponse(res) ((value)(res))
#define SfFtpResponse_val(res) ((sf::Ftp::Response *)(res))

#define Val_sfFtpDirectoryResponse(fdr) ((value)(fdr))
#define SfFtpDirectoryResponse_val(fdr) ((sf::Ftp::DirectoryResponse *)(fdr))

#define Val_sfFtpListingResponse(flr) ((value)(flr))
#define SfFtpListingResponse_val(flr) ((sf::Ftp::ListingResponse *)(flr))


CAMLextern_C value
caml_sfFtp_create(value unit)
{
    sf::Ftp *ftp = new sf::Ftp;
    return Val_sfFtp(ftp);
}

CAMLextern_C value
caml_sfFtp_destroy(value ftp)
{
    delete SfFtp_val(ftp);
    return Val_unit;
}

#include <cstdio>
CAMLextern_C value
caml_sfFtp_connect(
        value ftp, value server, value ml_port, value timeout, value unit)
{
    unsigned int pr = 0;
    unsigned short port;
//  long _port;
#if 0
#define conv_port() \
    _port = Option_val(ml_port, Long_val, 21); \
    port = _port; \
    if ((long)port != _port) \
        fprintf(stderr, "%h %d\n", port, _port);  fflush(stderr); \
        caml_invalid_argument("SFFtp.connect")
#endif
#if 0
#define conv_port() \
    port = Long_val(ml_port); \
    fprintf(stderr, "%h %d\n", port);  fflush(stderr);
#endif
 
    sf::Ftp::Response *resp = new sf::Ftp::Response;

    if (ml_port != Val_none) pr |= 0b0001;
    if (timeout != Val_none) pr |= 0b0010;

    switch (pr) {
        case 0b0000:
            *resp = SfFtp_val(ftp)->connect(
                    SfIpAddress_val(server));
            break;
        case 0b0001:
            //conv_port();
            port = Option_val(ml_port, Long_val, 21);
            *resp = SfFtp_val(ftp)->connect(
                    SfIpAddress_val(server), port);
            break;
        case 0b0011:
            //conv_port();
            port = Option_val(ml_port, Long_val, 21);
            *resp = SfFtp_val(ftp)->connect(
                    SfIpAddress_val(server), port, SfTime_val(timeout));
            break;
        case 0b0010:
            *resp = SfFtp_val(ftp)->connect(
                    SfIpAddress_val(server), 21, SfTime_val(timeout));
            break;
        default:
            caml_failwith("SFFtp.connect");
    }

    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_loginAnonymous(value ftp)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->login();
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_login(value ftp, value userName, value password)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->login(
            String_val(userName), String_val(password));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_disconnect(value ftp)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->disconnect();
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_keepAlive(value ftp)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->keepAlive();
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_getWorkingDirectory(value ftp)
{
    sf::Ftp::DirectoryResponse fdr = SfFtp_val(ftp)->getWorkingDirectory();

    sf::Ftp::DirectoryResponse *fdr2 = new sf::Ftp::DirectoryResponse(fdr);

    return Val_sfFtpDirectoryResponse(fdr2);
}

CAMLextern_C value
caml_sfFtp_getDirectoryListing(value ftp, value directory)
{
    sf::Ftp::ListingResponse l_resp =
        SfFtp_val(ftp)->getDirectoryListing(String_val(directory));

    sf::Ftp::ListingResponse *l_resp2 = new sf::Ftp::ListingResponse(l_resp);

    return Val_sfFtpListingResponse(l_resp2);
}

CAMLextern_C value
caml_sfFtp_changeDirectory(value ftp, value directory)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->changeDirectory(String_val(directory));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_parentDirectory(value ftp)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->parentDirectory();
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_createDirectory(value ftp, value name)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->createDirectory(String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_deleteDirectory(value ftp, value name)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->deleteDirectory(
            String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_renameFile(value ftp, value file, value newName)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->renameFile(
            String_val(file), String_val(newName));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_deleteFile(value ftp, value name)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->deleteFile(String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_download(value ftp, value distantFile, value destPath, value mode)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->download(
            String_val(distantFile), String_val(destPath),
            SfFtpTransferMode_val(mode));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtp_upload(value ftp, value localFile, value destPath, value mode)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->upload(
            String_val(localFile), String_val(destPath),
            SfFtpTransferMode_val(mode));
    return Val_sfFtpResponse(resp);
}

CAMLextern_C value
caml_sfFtpListingResponse_destroy(value ftpListingResponse)
{
    delete SfFtpListingResponse_val(ftpListingResponse);
    return Val_unit;
}

CAMLextern_C value
caml_sfFtpListingResponse_isOk(value ftpListingResponse)
{
    bool isOk = SfFtpListingResponse_val(ftpListingResponse)->isOk();
    return Val_bool(isOk);
}

CAMLextern_C value
caml_sfFtpListingResponse_getStatus(value ftpListingResponse)
{
    sf::Ftp::Response::Status status =
        SfFtpListingResponse_val(ftpListingResponse)->getStatus();
    return Val_sfFtpStatus(status);
}

CAMLextern_C value
caml_sfFtpListingResponse_getMessage(value ftpListingResponse)
{
    const std::string& msg =
        SfFtpListingResponse_val(ftpListingResponse)->getMessage();
    return caml_copy_string(msg.c_str());
}

CAMLextern_C value
caml_sfFtpListingResponse_getListing(value ftpListingResponse)
{
    CAMLparam1(ftpListingResponse);
    CAMLlocal1(ml_filename);

    unsigned int n, i;

    n = SfFtpListingResponse_val(ftpListingResponse)->getListing().size();

    const std::vector<std::string>& filenames =
        SfFtpListingResponse_val(ftpListingResponse)->getListing();

    ml_filename = caml_alloc(n, 0);

    for (i = 0; i < n; i++)
    {
        Store_field(ml_filename, i, caml_copy_string(filenames[i].c_str()));
    }

    CAMLreturn(ml_filename);
}

CAMLextern_C value
caml_sfFtpDirectoryResponse_destroy(value ftpDirectoryResponse)
{
    delete SfFtpDirectoryResponse_val(ftpDirectoryResponse);
    return Val_unit;
}

CAMLextern_C value
caml_sfFtpDirectoryResponse_isOk(value ftpDirectoryResponse)
{
    bool isOk = SfFtpDirectoryResponse_val(ftpDirectoryResponse)->isOk();
    return Val_bool(isOk);
}

CAMLextern_C value
caml_sfFtpDirectoryResponse_getStatus(value ftpDirectoryResponse)
{
    sf::Ftp::Response::Status status =
        SfFtpDirectoryResponse_val(ftpDirectoryResponse)->getStatus();
    return Val_sfFtpStatus(status);
}

CAMLextern_C value
caml_sfFtpDirectoryResponse_getMessage(value ftpDirectoryResponse)
{
    const std::string& msg =
        SfFtpDirectoryResponse_val(ftpDirectoryResponse)->getMessage();
    return caml_copy_string(msg.c_str());
}

CAMLextern_C value
caml_sfFtpDirectoryResponse_getDirectory(value ftpDirectoryResponse)
{
    const std::string& dir =
        SfFtpDirectoryResponse_val(ftpDirectoryResponse)->getDirectory();
    return caml_copy_string(dir.c_str());
}

CAMLextern_C value
caml_sfFtpResponse_destroy(value ftpResponse)
{
    delete SfFtpResponse_val(ftpResponse);
    return Val_unit;
}

CAMLextern_C value
caml_sfFtpResponse_isOk(value ftpResponse)
{
    bool isOk = SfFtpResponse_val(ftpResponse)->isOk();
    return Val_bool(isOk);
}

CAMLextern_C value
caml_sfFtpResponse_getStatus(value ftpResponse)
{
    sf::Ftp::Response::Status status =
        SfFtpResponse_val(ftpResponse)->getStatus();
    return Val_sfFtpStatus(status);
}

CAMLextern_C value
caml_sfFtpResponse_getMessage(value ftpResponse)
{
    const std::string& msg = SfFtpResponse_val(ftpResponse)->getMessage();
    return caml_copy_string(msg.c_str());
}

CAMLextern_C value
caml_sfFtp_sendCommand(value ftp, value command, value parameter)
{
    sf::Ftp::Response *resp = new sf::Ftp::Response;
    *resp = SfFtp_val(ftp)->sendCommand(String_val(command), String_val(parameter));
    return Val_sfFtpResponse(resp);
}

// vim: sw=4 sts=4 ts=4 et
