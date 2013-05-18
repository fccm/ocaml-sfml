type ftp
type response
type directoryResponse
type listingResponse

type status =
  | RestartMarkerReply
  | ServiceReadySoon
  | DataConnectionAlreadyOpened
  | OpeningDataConnection
  | Ok
  | PointlessCommand
  | SystemStatus
  | DirectoryStatus
  | FileStatus
  | HelpMessage
  | SystemType
  | ServiceReady
  | ClosingConnection
  | DataConnectionOpened
  | ClosingDataConnection
  | EnteringPassiveMode
  | LoggedIn
  | FileActionOk
  | DirectoryOk
  | NeedPassword
  | NeedAccountToLogIn
  | NeedInformation
  | ServiceUnavailable
  | DataConnectionUnavailable
  | TransferAborted
  | FileActionAborted
  | LocalError
  | InsufficientStorageSpace
  | CommandUnknown
  | ParametersUnknown
  | CommandNotImplemented
  | BadCommandSequence
  | ParameterNotImplemented
  | NotLoggedIn
  | NeedAccountToStore
  | FileUnavailable
  | PageTypeUnknown
  | NotEnoughMemory
  | FilenameNotAllowed
  | InvalidResponse
  | ConnectionFailed
  | ConnectionClosed
  | InvalidFile

type transferMode =
  | Binary
  | Ascii
  | Ebcdic

external create: unit -> ftp = "caml_sfFtp_create"
external destroy: ftp -> unit = "caml_sfFtp_destroy"

external connect: ftp -> server:SFIpAddress.t -> ?port:int ->
  ?timeout:SFTime.t -> unit -> response
  = "caml_sfFtp_connect"
external loginAnonymous: ftp -> response = "caml_sfFtp_loginAnonymous"
external login: ftp -> userName:string -> password:string -> response
  = "caml_sfFtp_login"
external disconnect: ftp -> response = "caml_sfFtp_disconnect"
external keepAlive: ftp -> response = "caml_sfFtp_keepAlive"

external changeDirectory: ftp -> directory:string -> response
  = "caml_sfFtp_changeDirectory"
external parentDirectory: ftp -> response
  = "caml_sfFtp_parentDirectory"
external createDirectory: ftp -> name:string -> response
  = "caml_sfFtp_createDirectory"
external deleteDirectory: ftp -> name:string -> response
  = "caml_sfFtp_deleteDirectory"
external renameFile: ftp -> file:string -> newName:string -> response
  = "caml_sfFtp_renameFile"
external deleteFile: ftp -> name:string -> response
  = "caml_sfFtp_deleteFile"

external upload: ftp -> localFile:string -> destPath:string ->
  mode:transferMode -> response
  = "caml_sfFtp_upload"
external download: ftp -> distantFile:string -> destPath:string ->
  mode:transferMode -> response
  = "caml_sfFtp_download"


module Response = struct
  external destroy: response -> unit = "caml_sfFtpResponse_destroy"
  external isOk: response -> bool = "caml_sfFtpResponse_isOk"
  external getStatus: response -> status = "caml_sfFtpResponse_getStatus"
  external getMessage: response -> string = "caml_sfFtpResponse_getMessage"
end

external getDirectoryListing: ftp -> directory:string -> listingResponse
  = "caml_sfFtp_getDirectoryListing"

module ListingResponse = struct
  external destroy: listingResponse -> unit
    = "caml_sfFtpListingResponse_destroy"
  external isOk: listingResponse -> bool
    = "caml_sfFtpListingResponse_isOk"
  external getStatus: listingResponse -> status
    = "caml_sfFtpListingResponse_getStatus"
  external getMessage: listingResponse -> string
    = "caml_sfFtpListingResponse_getMessage"
  external getListing: listingResponse -> string array
    = "caml_sfFtpListingResponse_getListing"
end

external getWorkingDirectory: ftp -> directoryResponse
  = "caml_sfFtp_getWorkingDirectory"

module DirectoryResponse = struct
  external destroy: directoryResponse -> unit
    = "caml_sfFtpDirectoryResponse_destroy"
  external isOk: directoryResponse -> bool
    = "caml_sfFtpDirectoryResponse_isOk"
  external getStatus: directoryResponse -> status
    = "caml_sfFtpDirectoryResponse_getStatus"
  external getMessage: directoryResponse -> string
    = "caml_sfFtpDirectoryResponse_getMessage"
  external getDirectory: directoryResponse -> string
    = "caml_sfFtpDirectoryResponse_getDirectory"
end

