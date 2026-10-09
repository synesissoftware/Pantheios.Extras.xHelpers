# Pantheios.Extras.xHelpers - TODO <!-- omit in toc -->


## Table of Contents <!-- omit in toc -->

- [Functional improvements](#functional-improvements)
- [Performance improvements](#performance-improvements)
- [Packaging improvements](#packaging-improvements)
- [Testing improvements](#testing-improvements)


## Functional improvements

* \<none>


## Performance improvements

* \<none>


## Packaging improvements

* Locate (or re-create) the generator for **com/internal/generated/invoke_nothrow.hpp**, so that the hand-patch can be replaced by regeneration;
* Remove **implicit_link.cpp** from **test.unit.xhelpers.functions.1**;
* Publish a tagged release containing the **CMake** packaging;


## Testing improvements

* Add Windows-only unit tests for the COM overloads (`HRESULT` mapping), and run them in CI;
* Add unit tests for the `invoke_nothrow_method()` overloads;


<!-- ########################### end of file ########################### -->
