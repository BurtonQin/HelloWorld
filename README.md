# Hello World Tutorial for Rust LLVM Instrumentation

## setup bashrc

Append the following code to ~/.bashrc:

Modify LLVM_INSTALL_DIR accordingly.
```
LLVM_INSTALL_DIR=$HOME/Env/llvm
export PATH=${LLVM_INSTALL_DIR}/bin:$PATH
export LLVM_DIR=${LLVM_INSTALL_DIR}/lib/cmake
export CMAKE_PREFIX_PATH=${LLVM_INSTALL_DIR}/lib/cmake
export LD_LIBRARY_PATH=${LLVM_INSTALL_DIR}/lib:$LD_LIBRARY_PATH
```
run ```. ~/.bashrc```

## stubs/hello

Pay attention to [profile.dev] in Cargo.toml. This is to avoid incremental compilation.

run ```cargo rustc -- --emit=llvm-bc```

The generated bc is in target/debug/deps/hello-*.bc

run```llvm-dis *.bc``` to generate human-readable *.ll file
 
## compilation
In dir HelloWorld:
```
mkdir cmake-build-debug
cd cmake-build-debug
cmake ..
make
```
We can find the generated libHelloPass.so in helloWorld/cmake-build-debug/lib/HelloPass/libHelloPass.so

## run
```
opt -load libHelloPass.so -hello hello-*.bc
```

we can print the function name and the first instruction of the function. 

