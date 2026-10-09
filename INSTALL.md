# Pantheios.Extras.xHelpers - Installation and Use <!-- omit in toc -->

**Pantheios.Extras.xHelpers** is a header-only C++ library: public
headers live under **include/pantheios/extras**. There is no compiled
`src` library target. Once the headers are on the include path (and
**Pantheios** and **STLSoft** 1.11.1-rc7 or later are available), include
**pantheios/extras/xhelpers.hpp** and call the `invoke_nothrow()` family.

Building the project's tests additionally requires **xTests**.


## Table of Contents <!-- omit in toc -->

- [CMake](#cmake)
- [Bundled](#bundled)


## CMake

The primary choice for installation is by use of **CMake**.

1. Obtain the latest distribution of **Pantheios.Extras.xHelpers**, from
   https://github.com/synesissoftware/Pantheios.Extras.xHelpers/, e.g.

   ```bash
   $ mkdir -p ~/open-source
   $ cd ~/open-source
   $ git clone https://github.com/synesissoftware/Pantheios.Extras.xHelpers/
   ```

2. Install **Pantheios** and **STLSoft** 1.11.1-rc7 or later (and
   **xTests** if you will build tests) via their own **CMake** scripts
   first.

3. Prepare the CMake configuration, via the **prepare_cmake.sh** script.

   Headers-and-examples only (no **xTests** required):

   ```bash
   $ cd ~/open-source/Pantheios.Extras.xHelpers
   $ ./prepare_cmake.sh --disable-testing -v
   ```

   Full build including examples and tests:

   ```bash
   $ cd ~/open-source/Pantheios.Extras.xHelpers
   $ ./prepare_cmake.sh -v
   ```

   If **STLSoft** is available as a source tree rather than an installed
   **CMake** package, pass its root with `--stlsoft-root-dir` / `-s`.

   (**Hint**: execute `$ ./prepare_cmake.sh --help` for more information.)

4. Run a build of the generated **CMake**-derived build files via the
   **build_cmake.sh** script, as in:

   ```bash
   $ ./build_cmake.sh
   ```

   (**NOTE**: if you provide the flag `--run-make` (=== `-m`) in step 3 then
   you do not need this step.)

5. As a check (when testing was not disabled), execute the built unit-test
   programs via **run_all_unit_tests.sh**, as in:

   ```bash
   $ ./run_all_unit_tests.sh
   ```

6. Install the headers (and **CMake** package files) on the host, via
   `cmake`, as in:

   ```bash
   $ sudo cmake --install ${SIS_CMAKE_BUILD_DIR:-./_build} --config Release
   ```

7. Then to use the library:

   1. A minimal consumer:

      ```cpp
      /* main.cpp */
      #include <pantheios/extras/xhelpers.hpp>

      #include <stdlib.h>

      static int api_(int x)
      {
          return x;
      }

      int api(int x)
      {
          int const rc = pantheios::extras::xhelpers::invoke_nothrow(
              api_, x
          ,   PANTHEIOS_LITERAL_STRING("api")
          ,   -1, -2, -3
          );

          return rc;
      }
      ```

   2. Compile against the installed include tree (and **Pantheios** /
      **STLSoft** as required by those packages):

      ```bash
      $ c++ -c main.cpp
      ```

   Consumers that use **CMake** need only find this package: its
   configuration locates **STLSoft** and **Pantheios** (when they were
   found as packages at build time) and the imported target brings their
   interfaces with it. **b64** is optional for **Pantheios**, and is
   found by **Pantheios**'s own package configuration as required:

   ```cmake
   find_package(pantheios.extras.xhelpers REQUIRED)
   target_link_libraries(your_target PRIVATE
       Pantheios.Extras.xHelpers::Pantheios.Extras.xHelpers)
   ```

   The Pantheios front-end and back-end libraries remain the program's
   own choice, and must be linked in addition.


## Bundled

**Pantheios.Extras.xHelpers** is small enough that it may be bundled into
other projects. In that case:

* add **Pantheios.Extras.xHelpers**'s **include** directory to your
  project's include path;
* ensure **Pantheios** and **STLSoft** headers are available; and
* `#include <pantheios/extras/xhelpers.hpp>`.


<!-- ########################### end of file ########################### -->
