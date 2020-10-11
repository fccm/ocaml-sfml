let do_this = function
  | "SFConfig"
  | "SFPausableClock"
  | "SFBlendMode"
  | "SFKey"
      -> `dont

  | "oo_sfml_system"
  | "oo_sfml_window"
  | "oo_sfml_graphics"
  | "oo_sfml_audio"
  | "oo_sfml_network"
      -> `group_doc

  | _ -> `class_doc

let add_class_doc basename =
  let mod_name = String.sub basename 2 (String.length basename - 2) in
  Printf.printf "(**  *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/classsf_1_1%s.php}
  Online documentation for the %s class} *)\n\n"
  mod_name
  mod_name

let add_group_doc basename =
  let mod_name = Scanf.sscanf basename "oo_sfml_%s" (fun s -> s) in
  Printf.printf "(** *)
(** {{:https://www.sfml-dev.org/documentation/2.5.1/group__%s.php}
  Online documentation for the %s module} *)\n\n"
  mod_name
  mod_name

let () =
  let basename = Filename.chop_extension Sys.argv.(1) in
  match do_this basename with
  | `class_doc -> add_class_doc basename
  | `group_doc -> add_group_doc basename
  | `dont -> ()
