# Pantheios.Extras.xHelpers - FAQ <!-- omit in toc -->

The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/Pantheios.Extras.xHelpers/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [Q1: "How do I build Pantheios.Extras.xHelpers?"](#q1-how-do-i-build-pantheiosextrasxhelpers)
- [Q2: "How do I install Pantheios.Extras.xHelpers?"](#q2-how-do-i-install-pantheiosextrasxhelpers)
- [Q3: "How do I use Pantheios.Extras.xHelpers?"](#q3-how-do-i-use-pantheiosextrasxhelpers)
- [Q4: "Which STLSoft version is required?"](#q4-which-stlsoft-version-is-required)


# FAQs: <!-- omit in toc -->

## Q1: "How do I build Pantheios.Extras.xHelpers?"

See [INSTALL.md](./INSTALL.md) for the recommended **CMake** flow
(**prepare_cmake.sh**, then **build_cmake.sh**). Install **Pantheios** and
**STLSoft** first. For tests, also install **xTests**, then:

```bash
$ ./prepare_cmake.sh -m
$ ./run_all_unit_tests.sh -M
```

Execute `$ ./prepare_cmake.sh --help` for the full set of options.


## Q2: "How do I install Pantheios.Extras.xHelpers?"

See [INSTALL.md](./INSTALL.md). The library is header-only; install copies
headers and **CMake** package files.


## Q3: "How do I use Pantheios.Extras.xHelpers?"

Include **pantheios/extras/xhelpers.hpp** and wrap each call that may throw
with `pantheios::extras::xhelpers::invoke_nothrow()`, nominating the return
codes for out-of-memory, handled exceptions and unexpected exceptions.

With **CMake**, link the INTERFACE target
`Pantheios.Extras.xHelpers::Pantheios.Extras.xHelpers` after
`find_package(pantheios.extras.xhelpers REQUIRED)`.


## Q4: "Which STLSoft version is required?"

**STLSoft** 1.11.1-rc7 or later. This is enforced by a compile-time check
in **internal/stlsoft.h**; the **CMake** package-version check can only
express 1.11.1, because package versions cannot name a pre-release.


<!-- ########################### end of file ########################### -->
