# Pantheios.Extras.xHelpers <!-- omit in toc -->

Header-only **C++** library in the **Pantheios.Extras** namespace that provides free-function templates (`invoke_nothrow()` and friends) for implementing non-throwing APIs.

![C++](https://img.shields.io/badge/C++-00599C?style=flat&logo=c%2B%2B&logoColor=white)
[![License](https://img.shields.io/badge/License-BSD_3--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)
[![GitHub release](https://img.shields.io/github/v/release/synesissoftware/Pantheios.Extras.xHelpers.svg)](https://github.com/synesissoftware/Pantheios.Extras.xHelpers/releases/latest)
[![Last Commit](https://img.shields.io/github/last-commit/synesissoftware/Pantheios.Extras.xHelpers)](https://github.com/synesissoftware/Pantheios.Extras.xHelpers/commits/master)
[![CI](https://github.com/synesissoftware/Pantheios.Extras.xHelpers/actions/workflows/ci.yml/badge.svg)](https://github.com/synesissoftware/Pantheios.Extras.xHelpers/actions/workflows/ci.yml)


## Table of Contents <!-- omit in toc -->

- [Introduction](#introduction)
  - [Why non-throwing wrappers](#why-non-throwing-wrappers)
  - [Dependencies](#dependencies)
- [Installation](#installation)
- [Components](#components)
  - [C-compatible API](#c-compatible-api)
  - [COM-compatible API](#com-compatible-api)
- [Examples](#examples)
- [Project Information](#project-information)
  - [Where to get help](#where-to-get-help)
  - [Contribution guidelines](#contribution-guidelines)
  - [Dependencies](#dependencies-1)
    - [Development dependencies](#development-dependencies)
  - [Related projects](#related-projects)
  - [License](#license)


## Introduction

**Pantheios.Extras.xHelpers** is a small **header-only** library under the [Pantheios](http://pantheios.org/) extras namespace. It provides a suite of free-function templates that simplify the implementation of non-throwing APIs that are:

* C-compatible; or
* COM-compatible (on Windows); or
* any other context where exceptions must be translated into return codes.

Each wrapper invokes a function (or member function) of 0 to 10 parameters inside an exception handler, logs any exception via **Pantheios**, and returns an error code that you nominate for out-of-memory, handled-exception, and unexpected-exception conditions.


### Why non-throwing wrappers

Hand-written `try`/`catch` blocks at every API boundary are repetitive and easy to get wrong:

* Every boundary must remember to catch `std::bad_alloc`, `std::exception`, and (optionally) everything else;
* Each handler must log consistently before translating to a return code;
* Out-of-memory handling must itself avoid allocating;

**Pantheios.Extras.xHelpers** centralises that protocol in one set of overloads.


### Dependencies

| Component     | Implemented in | Use in                                              | Dependencies |
| ------------- | -------------- | --------------------------------------------------- | ------------ |
| Core library  | C++ headers    | **pantheios/extras/xhelpers.hpp**                   | [Pantheios](https://github.com/synesissoftware/Pantheios), [STLSoft](https://github.com/synesissoftware/STLSoft/) 1.11.1-rc7+ |
| Examples      | C++            | —                                                   | Pantheios, STLSoft |
| Tests         | C++            | —                                                   | Pantheios, STLSoft, [xTests](https://github.com/synesissoftware/xTests/) |


## Installation

Detailed instructions — via **CMake**, via bundling — are provided in the accompanying [INSTALL.md](./INSTALL.md) file.


## Components

### C-compatible API

```C++
#include <pantheios/extras/xhelpers.hpp>

namespace pantheios {
namespace extras {
namespace xhelpers {

// 0..10 parameter overloads (and cdecl/stdcall and member-function forms)
template <typename R, typename A0>
R invoke_nothrow(
    R (*pfn)(A0)
,   A0 a0
,   pan_char_t const* functionName
,   R bad_alloc_code, R unhandled_code, R unexpected_code
);

} // namespace xhelpers
} // namespace extras
} // namespace pantheios
```


### COM-compatible API

On Windows, **pantheios/extras/xhelpers/com.hpp** provides `HRESULT`-returning equivalents that map out-of-memory to `E_OUTOFMEMORY` and handled exceptions to `E_FAIL`.


## Examples

Examples are provided in the `examples` directory (`example.cpp.invoke_nothrow.1`).


## Project Information


### Where to get help

[GitHub Page](https://github.com/synesissoftware/Pantheios.Extras.xHelpers)


### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/Pantheios.Extras.xHelpers.


### Dependencies

* [Pantheios](https://github.com/synesissoftware/Pantheios);
* [STLSoft](https://github.com/synesissoftware/STLSoft/) 1.11.1-rc7 or later;


#### Development dependencies

* [xTests](https://github.com/synesissoftware/xTests/);


### Related projects

* [Pantheios](https://github.com/synesissoftware/Pantheios);
* [Pantheios.Extras.AtExit](https://github.com/synesissoftware/Pantheios.Extras.AtExit);
* [Pantheios.Extras.DiagUtil](https://github.com/synesissoftware/Pantheios.Extras.DiagUtil);
* [Pantheios.Extras.Main](https://github.com/synesissoftware/Pantheios.Extras.Main);


### License

**Pantheios.Extras.xHelpers** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->
