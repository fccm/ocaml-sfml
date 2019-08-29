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

If you want to donate something to the author of the ocaml bindings (me)
I don't accept any money donation, but I would be interested by books.


=== C vs. C++ API ===

The main API of SFML is in C++ but a C API is also available.
The first version of ocaml-sfml was wrapping the C API.
During the transition from SFML 1.6 to 2.0 the decision was taken to wrap
the C++ API because several very interesting projects are provided for
this API, and it will be easier to use those with bindings to the C++ API.
But the binding to the C++ API is more recent, so the binding to the C API
has probably less bugs, if any.

The OCaml interface is exactly the same, whether the stubs wrap the C++ API
or the C API. Only the C or C++ stubs are different.


=== Compile ===

##### Compile for the C++ API:

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

If the SFML library is in a custom path, for example a directory
"/tmp/my_sfml" that contains at least 2 directories, one "lib/" containing
the *.so files and "include/" containing the headers, you can build this way:

$ make cxx_all LIB_SFML_BASEDIR=/tmp/my_sfml


##### Compile for the C API:

The targets are the same, except that you should replace "cxx" by "c".

In order to compile for the C API of SFML (called CSFML), the compilation
script should be able to find the headers of CSFML (the headers of SFML
are not needed for this one), and the *.so files for both SFML and CSFML.

If both sfml and csfml *.so files are in a directory "/custom/path/lib"
and the headers of CSFML are in "/non/standard/include"
then use:
$ make <c-api-target> LD_PATH=-L/custom/path/lib \
    C_INC_PATH=-I/non/standard/include

If the *.so of sfml are in /custom/sfml/lib and the *.so of csfml are
in /custom/Csfml/lib and the headers of csfml are in /my/Csfml/include
then use:
$ make <c-api-target> \
    CXX_LD_DIR=/custom/sfml/lib \
    C_LD_DIR=/custom/Csfml/lib \
    C_INC_DIR=/my/Csfml/include


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


=== PausableClock ===

PausableClock is not part of the SFML library, but have been included in the
bindings because it has been found usefull.
The author of PausableClock gave the permission to use it under the same
license than SFML (zlib/png).


=== Miscellaneous ===

The SFML_oo module is equivalent to all the other modules but provides an
Object Oriented style.


=== Friends Projects ===

There is another binding that we are aware of that is Ocsfml available at:
https://github.com/JoeDralliam/Ocsfml
Although the stubs code are very different between ocaml-sfml and ocsfml,
the resulting OCaml interface are quite close, modulo the namings of the
functions and the module packing that are different.
I have no opinion whether which one could be considered the best one, but
I think that the source code of ocaml-sfml is probably simpler.

