# Finance, Mathematics, Software https://ci.appveyor.com/api/projects/status/q47rcuonkk4unyam/branch/master?svg=true


## Layout

This is a header only library and will ultimately use C++ modules.

It is designed for dual use by creating a `.cpp` file that includes the header that exports all functions.
The headers make clear what is to be exported.

## Build

This library uses modern cmake to build, test, and package libfms.

## Test

We use `ensure` from [`ensure.h`](include/ensure.h) for unit testing. By default it will put you in the
appropriate debugger for your platform. Turn it off by defining `NENSURE` or replace it with
`assert(3)` by defining `ENSURE_ASSERT`. 

Code should never be checked in that fails any test. Development/CI builds should define `ENSURE_ASSERT`
which will call `abort(3)` and send an electric shock to the offending developer. Production builds
should define `NENSURE` and pass integration testing before release.

## NOTES

Use [UTF-8 everywhere](https://utf8everywhere.org/) and `widen()/narrow()` from `<locale>` at points of usage.

### MSVC Modules

To turn a header file into a module in MSVC create a `.cpp` file including the header.

Compile with `cl -experimental:module -module:export .\mymodule.cpp -module:mymodule file -c /EHsc /nologo`
to create a `mymodule.ifc`. Link this and the corresponding `.obj` files.

## Set compiler on Ubuntu

`sudo update-alternatives --config c++`
