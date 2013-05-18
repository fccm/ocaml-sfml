open SFTransform

let print_matrix t =
  let m = SFTransform.getMatrix t in
  Printf.printf "  \
    %g %g %g %g\n  \
    %g %g %g %g\n  \
    %g %g %g %g\n  \
    %g %g %g %g\n\n%!"
    m.(0)   m.(1)   m.(2)   m.(3)
    m.(4)   m.(5)   m.(6)   m.(7)
    m.(8)   m.(9)   m.(10)  m.(11)
    m.(12)  m.(13)  m.(14)  m.(15)

let () =
  let t = SFTransform.getIdentity () in
  print_matrix t

let () =
  let matrix = {
    a00 = 0.00;
    a01 = 0.01;
    a02 = 0.02;
    a10 = 0.10;
    a11 = 0.11;
    a12 = 0.12;
    a20 = 0.20;
    a21 = 0.21;
    a22 = 0.22;
  } in
  let t = SFTransform.fromMatrix ~matrix in
  print_matrix t
