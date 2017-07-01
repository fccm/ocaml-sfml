type http_method =
  | Get
  | Post
  | Head
  | Put
  | Delete

type status =
  | Ok
  | Created
  | Accepted
  | NoContent
  | ResetContent
  | PartialContent
  | MultipleChoices
  | MovedPermanently
  | MovedTemporarily
  | NotModified
  | BadRequest
  | Unauthorized
  | Forbidden
  | NotFound
  | RangeNotSatisfiable
  | InternalServerError
  | NotImplemented
  | BadGateway
  | ServiceNotAvailable
  | GatewayTimeout
  | VersionNotSupported
  | InvalidResponse
  | ConnectionFailed

module Request = struct
type t
external create: unit -> t = "caml_sfHttpRequest_create"
external destroy: t -> unit = "caml_sfHttpRequest_destroy"
(* TODO: check for the string input *)
external setField: t -> field:string -> value:string -> unit
  = "caml_sfHttpRequest_setField"
(* TODO: check for the string input *)
external setMethod: t -> http_method -> unit
  = "caml_sfHttpRequest_setMethod"
(* TODO: check for the string input *)
external setUri: t -> uri:string -> unit
  = "caml_sfHttpRequest_setUri"
external setHttpVersion: t -> major:int -> minor:int -> unit
  = "caml_sfHttpRequest_setHttpVersion"
(* TODO: check for the string input *)
external setBody: t -> body:string -> unit
  = "caml_sfHttpRequest_setBody"
end

module Response = struct
type t
external getBody: t -> string = "caml_sfHttpResponse_getBody"
external getStatus: t -> status = "caml_sfHttpResponse_getStatus"
external destroy: t -> unit = "caml_sfHttpResponse_destroy"
external getField: t -> field:string -> string = "caml_sfHttpResponse_getField"
external getMajorHttpVersion: t -> int
  = "caml_sfHttpResponse_getMajorHttpVersion"
external getMinorHttpVersion: t -> int
  = "caml_sfHttpResponse_getMinorHttpVersion"
end

type t
external create: unit -> t = "caml_sfHttp_create"
external destroy: t -> unit = "caml_sfHttp_destroy"
external setHost: t -> host:string -> ?port:int -> unit -> unit = "caml_sfHttp_setHost"
external sendRequest: t -> request:Request.t -> ?timeout:SFTime.t -> unit -> Response.t
  = "caml_sfHttp_sendRequest"
