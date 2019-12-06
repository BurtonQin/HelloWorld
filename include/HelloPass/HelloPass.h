#ifndef HELLOWORLD_HELLOPASS_H
#define HELLOWORLD_HELLOPASS_H

#include "llvm/Pass.h"

struct HelloPass: public llvm::ModulePass {

    static char ID;
    HelloPass();

    virtual void getAnalysisUsage(llvm::AnalysisUsage &AU) const;
    virtual bool runOnModule(llvm::Module &M);
};

#endif //HELLOWORLD_HELLOPASS_H
