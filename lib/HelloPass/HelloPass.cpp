#include "HelloPass/HelloPass.h"

#include "llvm/IR/Dominators.h"

using namespace llvm;

#define DEBUG_TYPE "HelloPass"

static RegisterPass<HelloPass> X("hello", "tutorial for llvm pass", false, false);

char HelloPass::ID = 0;

HelloPass::HelloPass() : ModulePass(ID) {
    PassRegistry &Registry = *PassRegistry::getPassRegistry();
    initializeDominatorTreeWrapperPassPass(Registry);
}

void HelloPass::getAnalysisUsage(AnalysisUsage &AU) const {
    AU.setPreservesAll();
    AU.addRequired<DominatorTreeWrapperPass>();
}

bool HelloPass::runOnModule(Module &M) {
    for (Function &F : M) {
        if (F.begin() == F.end()) {
            continue;
        }
        errs().write_escaped(F.getName()) << "\n";
        for (BasicBlock &BB : F) {
            for (Instruction &II : BB) {
                // Instrument your own function
                II.print(errs());
                errs() << "\n";
                // use II.dump() instead print if possible.
                break;
            }
        }
    }
    return true;
}