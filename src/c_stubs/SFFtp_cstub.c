/*
 * OCaml-SFML - OCaml bindings for the SFML library.
 * Copyright (C) 2010 Florent Monnier <monnier.florent(_)gmail.com>
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

#include <SFML/Network/Ftp.h>

#include "sf_caml_incs_c.h"
#include "sf_caml_conv_c.h"
#include "SFIpAddress_cstub.h"
#include "SFTime_cstub.h"


static const sfFtpStatus ml_table_sfFtpStatus[] = {
    sfFtpRestartMarkerReply,
    sfFtpServiceReadySoon,
    sfFtpDataConnectionAlreadyOpened,
    sfFtpOpeningDataConnection,
    sfFtpOk,
    sfFtpPointlessCommand,
    sfFtpSystemStatus,
    sfFtpDirectoryStatus,
    sfFtpFileStatus,
    sfFtpHelpMessage,
    sfFtpSystemType,
    sfFtpServiceReady,
    sfFtpClosingConnection,
    sfFtpDataConnectionOpened,
    sfFtpClosingDataConnection,
    sfFtpEnteringPassiveMode,
    sfFtpLoggedIn,
    sfFtpFileActionOk,
    sfFtpDirectoryOk,
    sfFtpNeedPassword,
    sfFtpNeedAccountToLogIn,
    sfFtpNeedInformation,
    sfFtpServiceUnavailable,
    sfFtpDataConnectionUnavailable,
    sfFtpTransferAborted,
    sfFtpFileActionAborted,
    sfFtpLocalError,
    sfFtpInsufficientStorageSpace,
    sfFtpCommandUnknown,
    sfFtpParametersUnknown,
    sfFtpCommandNotImplemented,
    sfFtpBadCommandSequence,
    sfFtpParameterNotImplemented,
    sfFtpNotLoggedIn,
    sfFtpNeedAccountToStore,
    sfFtpFileUnavailable,
    sfFtpPageTypeUnknown,
    sfFtpNotEnoughMemory,
    sfFtpFilenameNotAllowed,
    sfFtpInvalidResponse,
    sfFtpConnectionFailed,
    sfFtpConnectionClosed,
    sfFtpInvalidFile,
};

#define SfFtpStatus_val(v) \
    (ml_table_sfFtpStatus[Long_val(v)])


value
Val_sfFtpStatus(sfFtpStatus e)
{
    switch (e)
    {
        case sfFtpRestartMarkerReply:           return Val_long(0);
        case sfFtpServiceReadySoon:             return Val_long(1);
        case sfFtpDataConnectionAlreadyOpened:  return Val_long(2);
        case sfFtpOpeningDataConnection:        return Val_long(3);
        case sfFtpOk:                           return Val_long(4);
        case sfFtpPointlessCommand:             return Val_long(5);
        case sfFtpSystemStatus:                 return Val_long(6);
        case sfFtpDirectoryStatus:              return Val_long(7);
        case sfFtpFileStatus:                   return Val_long(8);
        case sfFtpHelpMessage:                  return Val_long(9);
        case sfFtpSystemType:                   return Val_long(10);
        case sfFtpServiceReady:                 return Val_long(11);
        case sfFtpClosingConnection:            return Val_long(12);
        case sfFtpDataConnectionOpened:         return Val_long(13);
        case sfFtpClosingDataConnection:        return Val_long(14);
        case sfFtpEnteringPassiveMode:          return Val_long(15);
        case sfFtpLoggedIn:                     return Val_long(16);
        case sfFtpFileActionOk:                 return Val_long(17);
        case sfFtpDirectoryOk:                  return Val_long(18);
        case sfFtpNeedPassword:                 return Val_long(19);
        case sfFtpNeedAccountToLogIn:           return Val_long(20);
        case sfFtpNeedInformation:              return Val_long(21);
        case sfFtpServiceUnavailable:           return Val_long(22);
        case sfFtpDataConnectionUnavailable:    return Val_long(23);
        case sfFtpTransferAborted:              return Val_long(24);
        case sfFtpFileActionAborted:            return Val_long(25);
        case sfFtpLocalError:                   return Val_long(26);
        case sfFtpInsufficientStorageSpace:     return Val_long(27);
        case sfFtpCommandUnknown:               return Val_long(28);
        case sfFtpParametersUnknown:            return Val_long(29);
        case sfFtpCommandNotImplemented:        return Val_long(30);
        case sfFtpBadCommandSequence:           return Val_long(31);
        case sfFtpParameterNotImplemented:      return Val_long(32);
        case sfFtpNotLoggedIn:                  return Val_long(33);
        case sfFtpNeedAccountToStore:           return Val_long(34);
        case sfFtpFileUnavailable:              return Val_long(35);
        case sfFtpPageTypeUnknown:              return Val_long(36);
        case sfFtpNotEnoughMemory:              return Val_long(37);
        case sfFtpFilenameNotAllowed:           return Val_long(38);
        case sfFtpInvalidResponse:              return Val_long(39);
        case sfFtpConnectionFailed:             return Val_long(40);
        case sfFtpConnectionClosed:             return Val_long(41);
        case sfFtpInvalidFile:                  return Val_long(42);

        default: caml_failwith("SFFtp.status");
    }
    caml_failwith("SFFtp.status");
}


static const sfFtpTransferMode ml_table_sfFtpTransferMode[] = {
    sfFtpBinary,
    sfFtpAscii,
    sfFtpEbcdic,
};

#define SfFtpTransferMode_val(v) \
    (ml_table_sfFtpTransferMode[Long_val(v)])

value
Val_sfFtpTransferMode(sfFtpTransferMode e)
{
    switch (e)
    {
        case sfFtpBinary:       return Val_long(0);
        case sfFtpAscii:        return Val_long(1);
        case sfFtpEbcdic:       return Val_long(2);

        default: caml_failwith("SFFtp.transferMode");
    }
    caml_failwith("SFFtp.transferMode");
}

#define Val_sfFtp(ftp) ((value)(ftp))
#define SfFtp_val(ftp) ((sfFtp *)(ftp))

#define Val_sfFtpResponse(res) ((value)(res))
#define SfFtpResponse_val(res) ((sfFtpResponse *)(res))

#define Val_sfFtpDirectoryResponse(fdr) ((value)(fdr))
#define SfFtpDirectoryResponse_val(fdr) ((sfFtpDirectoryResponse *)(fdr))

#define Val_sfFtpListingResponse(flr) ((value)(flr))
#define SfFtpListingResponse_val(flr) ((sfFtpListingResponse *)(flr))


CAMLprim value
caml_sfFtp_create(value unit)
{
    sfFtp *ftp = sfFtp_create();
    return Val_sfFtp(ftp);
}

CAMLprim value
caml_sfFtp_destroy(value ftp)
{
    sfFtp_destroy(SfFtp_val(ftp));
    return Val_unit;
}

CAMLprim value
caml_sfFtp_connect(
        value ftp, value server, value ml_port, value ml_timeout, value unit)
{
    const char *f_name = "SFFtp.connect";
    unsigned short port;
    sfTime timeout;
    sfFtpResponse *resp;

    if (ml_port == Val_none) {
        port = 21;
    } else {
        long _port = Long_val(ml_port);
        port = _port;
        if ((long)port != _port)
            caml_invalid_argument(f_name);
    }

    if (ml_timeout == Val_none) {
        timeout = sfTime_Zero;
    } else {
        timeout = SfTime_val(ml_timeout);
    }

    resp = sfFtp_connect(
            SfFtp_val(ftp), SfIpAddress_val(server, f_name), port, timeout);

    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_loginAnonymous(value ftp)
{
    sfFtpResponse *resp = sfFtp_loginAnonymous(SfFtp_val(ftp));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_login(value ftp, value userName, value password)
{
    sfFtpResponse *resp = sfFtp_login(
            SfFtp_val(ftp), String_val(userName), String_val(password));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_disconnect(value ftp)
{
    sfFtpResponse *resp = sfFtp_disconnect(SfFtp_val(ftp));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_keepAlive(value ftp)
{
    sfFtpResponse *resp = sfFtp_keepAlive(SfFtp_val(ftp));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_getWorkingDirectory(value ftp)
{
    sfFtpDirectoryResponse *fdr = sfFtp_getWorkingDirectory(SfFtp_val(ftp));
    return Val_sfFtpDirectoryResponse(fdr);
}

CAMLprim value
caml_sfFtp_getDirectoryListing(value ftp, value directory)
{
    sfFtpListingResponse *l_resp = sfFtp_getDirectoryListing(
            SfFtp_val(ftp), String_val(directory));
    return Val_sfFtpListingResponse(l_resp);
}

CAMLprim value
caml_sfFtp_changeDirectory(value ftp, value directory)
{
    sfFtpResponse *resp = sfFtp_changeDirectory(
            SfFtp_val(ftp), String_val(directory));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_parentDirectory(value ftp)
{
    sfFtpResponse *resp = sfFtp_parentDirectory(SfFtp_val(ftp));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_createDirectory(value ftp, value name)
{
    sfFtpResponse *resp = sfFtp_createDirectory(
            SfFtp_val(ftp), String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_deleteDirectory(value ftp, value name)
{
    sfFtpResponse *resp = sfFtp_deleteDirectory(
            SfFtp_val(ftp), String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_renameFile(value ftp, value file, value newName)
{
    sfFtpResponse *resp = sfFtp_renameFile(
            SfFtp_val(ftp), String_val(file), String_val(newName));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_deleteFile(value ftp, value name)
{
    sfFtpResponse *resp = sfFtp_deleteFile(SfFtp_val(ftp), String_val(name));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_download(value ftp, value distantFile, value destPath, value mode)
{
    sfFtpResponse *resp = sfFtp_download(
            SfFtp_val(ftp), String_val(distantFile), String_val(destPath),
            SfFtpTransferMode_val(mode));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtp_upload(value ftp, value localFile, value destPath, value mode)
{
    sfFtpResponse *resp = sfFtp_upload(
            SfFtp_val(ftp), String_val(localFile), String_val(destPath),
            SfFtpTransferMode_val(mode));
    return Val_sfFtpResponse(resp);
}

CAMLprim value
caml_sfFtpListingResponse_destroy(value ftpListingResponse)
{
    sfFtpListingResponse_destroy(SfFtpListingResponse_val(ftpListingResponse));
    return Val_unit;
}

CAMLprim value
caml_sfFtpListingResponse_isOk(value ftpListingResponse)
{
    sfBool isOk = sfFtpListingResponse_isOk(
            SfFtpListingResponse_val(ftpListingResponse));
    return Val_bool(isOk);
}

CAMLprim value
caml_sfFtpListingResponse_getStatus(value ftpListingResponse)
{
    sfFtpStatus status = sfFtpListingResponse_getStatus(
            SfFtpListingResponse_val(ftpListingResponse));
    return Val_sfFtpStatus(status);
}

CAMLprim value
caml_sfFtpListingResponse_getMessage(value ftpListingResponse)
{
    const char *msg = sfFtpListingResponse_getMessage(
            SfFtpListingResponse_val(ftpListingResponse));
    return caml_copy_string(msg);
}

CAMLprim value
caml_sfFtpListingResponse_getListing(value ftpListingResponse)
{
    CAMLparam1(ftpListingResponse);
    CAMLlocal1(ml_filename);

    size_t n;
    unsigned int i;
    const char *filename;

    n = sfFtpListingResponse_getCount(
            SfFtpListingResponse_val(ftpListingResponse));

    ml_filename = caml_alloc(n, 0);

    for (i = 0; i < n; i++)
    {
        filename = sfFtpListingResponse_getName(
                SfFtpListingResponse_val(ftpListingResponse), i);

        Store_field(ml_filename, i, caml_copy_string(filename));
    }

    CAMLreturn(ml_filename);
}

CAMLprim value
caml_sfFtpDirectoryResponse_destroy(value ftpDirectoryResponse)
{
    sfFtpDirectoryResponse_destroy(
            SfFtpDirectoryResponse_val(ftpDirectoryResponse));
    return Val_unit;
}

CAMLprim value
caml_sfFtpDirectoryResponse_isOk(value ftpDirectoryResponse)
{
    sfBool isOk = sfFtpDirectoryResponse_isOk(
            SfFtpDirectoryResponse_val(ftpDirectoryResponse));
    return Val_bool(isOk);
}

CAMLprim value
caml_sfFtpDirectoryResponse_getStatus(value ftpDirectoryResponse)
{
    sfFtpStatus status = sfFtpDirectoryResponse_getStatus(
            SfFtpDirectoryResponse_val(ftpDirectoryResponse));
    return Val_sfFtpStatus(status);
}

CAMLprim value
caml_sfFtpDirectoryResponse_getMessage(value ftpDirectoryResponse)
{
    const char *msg = sfFtpDirectoryResponse_getMessage(
            SfFtpDirectoryResponse_val(ftpDirectoryResponse));
    return caml_copy_string(msg);
}

CAMLprim value
caml_sfFtpDirectoryResponse_getDirectory(value ftpDirectoryResponse)
{
    const char *dir = sfFtpDirectoryResponse_getDirectory(
            SfFtpDirectoryResponse_val(ftpDirectoryResponse));
    return caml_copy_string(dir);
}

CAMLprim value
caml_sfFtpResponse_destroy(value ftpResponse)
{
    sfFtpResponse_destroy(SfFtpResponse_val(ftpResponse));
    return Val_unit;
}

CAMLprim value
caml_sfFtpResponse_isOk(value ftpResponse)
{
    sfBool isOk = sfFtpResponse_isOk(SfFtpResponse_val(ftpResponse));
    return Val_bool(isOk);
}

CAMLprim value
caml_sfFtpResponse_getStatus(value ftpResponse)
{
    sfFtpStatus status =
        sfFtpResponse_getStatus(SfFtpResponse_val(ftpResponse));
    return Val_sfFtpStatus(status);
}

CAMLprim value
caml_sfFtpResponse_getMessage(value ftpResponse)
{
    const char *msg = sfFtpResponse_getMessage(SfFtpResponse_val(ftpResponse));
    return caml_copy_string(msg);
}

/* vim: sw=4 sts=4 ts=4 et
 */
