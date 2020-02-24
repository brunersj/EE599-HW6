# EE599 HW 5 - Sam Bruner

> Can be used in Visual Studio Code

Features:

- [x] Building C++ files using Bazel in Visual Studio Code
- [x] Testing your code using [Google Test](https://github.com/google/googletest)
- [x] Debugging with [CodeLLDB Extension](https://marketplace.visualstudio.com/items?itemName=vadimcn.vscode-lldb) to provide pretty printing for STL containers such as `std::map` and `std::vector`.


### Run main:

You can run this using `blaze`:

```bash
bazel run src/main:main
```

### Run Tests:

You can run unit tests using [`blaze`](installing-bazel):

```bash
bazel test tests:tests
```

### Credits

Implementation of Tree methods inspired by Prof Rob Edwards SDSU. https://www.youtube.com/channel/UC6Aa5t0vHN8uj_BCbgrRZcQ