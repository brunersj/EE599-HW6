# EE599 HW 6 - Sam Bruner

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
Reused BST code from HW 5 for question 6 implementation. Inserted the element at the desired index as the root of the BST. As a result, all of the elements to the left of the root in the vector will be less than it.