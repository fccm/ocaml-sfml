=== Description ===

These are OCaml bindings for the SFML library.
SFML stands for "Simple and Fast Multimedia Library".
The SFML is a library for multimedia programming.

OCaml is a fast and powerful language for application
development.


=== License ===

These bindings are released under the zlib/png license.
This is the same license than the SFML library, this is
why this license was chosen.
But for any reason if you prefer the MIT, the BSD, the ISC,
the GPL or the LGPL license (or even CC0), just switch to it!


=== Home-Page ===

ocaml-sfml is hosted on GitHub.
The home page of ocaml-sfml is:
  https://github.com/fccm/ocaml-sfml
The releases can be found at:
  https://github.com/fccm/ocaml-sfml/releases

The home page of the SFML project is:
  http://www.sfml-dev.org/

OCaml's home page is:
  http://ocaml.org/


=== Versions ===

This version of the bindings have been tested with SFML 2.5.1
and OCaml 4.11.1


=== Authors ===

The main author of the SFML library is Laurent Gomila.
(You can write to him to thank him for his work at <laurent()sfml-dev.org>.)
The main author of the ocaml-sfml bindings is Florent Monnier (contact
by email: <monnier.florent()gmail.com>).
Jérémie Dimino also contributed to ocaml-sfml (email: <jeremie()dimino.org>).
Sylvain Boilard made a lot of changes to update to the SFML versions 2.2 and
2.4 (email <boilard()crans.org>).

You can get more details about the contributions in the file "Authors.txt",
or browsing the history of the SCM.

Laurent Gomila also helped for ocaml-sfml by answering several questions.


=== Donate ===

If you think SFML is useful for you, you can make a donation
to the author of SFML, Laurent Gomila:
https://www.paypal.com/cgi-bin/webscr/?cmd=_s-xclick&hosted_button_id=TYJ2XQPG3SXPG

If you want to donate something to the author of the ocaml bindings:
https://www.paypal.com/donate?business=monnier.florent@gmail.com&item_name=ocaml-sfml


=== C vs. C++ API ===

The main API of SFML is in C++ but a C API is also available.
The first version of ocaml-sfml was wrapping the C API only.

During the transition from SFML 1.6 to 2.0 the decision was made to wrap
the C++ API also because several very interesting projects are provided for
this API, and it will be easier to use those with bindings to the C++ API.

For several versions of ocaml-sfml it was possible to compile with C stubs
or C++ stubs, each respectively linking with the C lib or the C++ lib of SFML.

The OCaml interface was exactly the same, whether we were using the stubs for
the C++ API or for the C API. Only the C or C++ stubs were different.

Today only the C++ stubs are maintained because it require more work to maintain
both, and also when a new version of the SFML is released, the C++ always comes
first, and the C lib usualy comes quite a lot of time later.


=== Compile ===

You can use these "make" targets:

- cxx_byte, to build the bytecode modules
- cxx_opt, to build the native modules
- cxx, to build both
- cxx_cmxs, to build the native plugin

- cxx_oo_byte, to build the bytecode of the OO style module
- cxx_oo_opt, to build the native of the OO style module
- cxx_oo_cmxs, to build the plugin of the OO style module

- cxx_all, to build all the previous ones

- install_cxx, to install the build files
  (this target will install the files using the 'install' command line tool)

- findinstall, to install the build files using the ocamlfind tool
  (if you're using opam, this target will install inside the ~/.opam subdirectory)

If the SFML library is in a custom path, for example a directory
"/tmp/my_sfml" that contains at least 2 directories, one "lib/" containing
the *.so files and "include/" containing the headers, you can build this way:

$ make cxx_all LIB_SFML_BASEDIR=/tmp/my_sfml


=== Opam ===

You can compile and install this local repository with:

$ opam install .

Or you can install the last released version published in the public Opam
repository with:

$ opam install sfml



=== Documentation ===

No ocamldoc comments have been added in the source code, so the ocamldoc
generated documentation will only provide you the signature of the interface.
But you should be able to read the SFML documentation, while OCaml module names
are the C++ classes names, and OCaml function names are the C++ methods names.

For example:
      SFMusic.setVolume
is equivalent to:
      sf::Music.setVolume

At the beginning of each module, there is though an ocamldoc link to the
documentation of the matching SFML class.

Run this command to build the ocamldoc HTML documentation:
$ make doc

This documentation can also be browsed online at:
http://fccm.github.io/ocaml-sfml/


=== PausableClock ===

PausableClock is not part of the SFML library, but have been included in the
bindings because it has been found usefull.
The author of PausableClock gave the permission to use it under the same
license than SFML (zlib/png).
PausableClock was rewritten later in pure OCaml by Sylvain Boilard.


=== Miscellaneous ===

The Oo_sfml_* modules are equivalent to all the other modules but provide an
Object Oriented style.


=== Friends Projects ===

There is another binding that we are aware of that is Ocsfml available at:
https://github.com/JoeDralliam/Ocsfml
Although the stubs code are very different between ocaml-sfml and ocsfml,
the resulting OCaml interface are quite close, modulo the namings of the
functions and the module packing that are different.
I have no opinion whether which one could be considered the best one, but
I think that the source code of ocaml-sfml is probably simpler.

