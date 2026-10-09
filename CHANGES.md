# Pantheios.Extras.xHelpers - Changes <!-- omit in toc -->


## 0.1.3-beta1 - 9th October 2026

* Added **CMake** build (`BUILD_TESTING`, `BUILD_EXAMPLES`), exported INTERFACE target `Pantheios.Extras.xHelpers::Pantheios.Extras.xHelpers`, and installed package `pantheios.extras.xhelpers` whose configuration re-finds **STLSoft** and **Pantheios** when they were located as packages;
* Added GitHub Actions CI (**ci.yml** / **ci-cell.yml**) with install smoke, using the **install-sis-deps** composite action;
* Added **test.unit.version**, **test.scratch.versions** and the **example.cpp.invoke_nothrow.1** example;
* Added helper scripts (**prepare_cmake.sh**, **build_cmake.sh**, **run_all_\*_tests.sh** and Windows `.cmd` counterparts) and **.sis/** project identity;
* Required **STLSoft** 1.11.1-rc7 or later;
* Fixed `invoke_nothrow()` 1-parameter COM overload forwarding a spurious template argument (hand-patched in **com/internal/generated/invoke_nothrow.hpp**; the generator is not in this repository);
* Fixed unused-parameter diagnostics in `invoke_nothrow_method()` overloads, so that no warning suppression is required;
* Removed obsolete **pantheios/extras/com/exception_helpers.hpp** shim (an `#error`-only header);
* Replaced out-of-memory unit tests that relied on a large `new` failing (which succeeds on 64-bit hosts) with a direct `throw std::bad_alloc()`;
* Added **README.md**, **INSTALL.md**, **FAQ.md**, **AUTHORS.md**, **CHANGES.md**, **NEWS.md** and **TODO.md**;


## 0.1.2 - 14th March 2017

* Fixed version information;


## 0.1.1 - 15th September 2015

* Initial public release, adding **LICENSE** and **README.md**;


<!-- ########################### end of file ########################### -->
