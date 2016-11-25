
#include <iostream>

#include <TChain.h>


int main(int argc, char** argv)
{


	TChain mtTree("mt/ntuple");
	int nFiles = mtTree.Add("/.automount/home/home__home2/institut_3b/pistone/pub/ntupleForStudents.root");
	std::cout << "Tree \"mt/ntuple\" initialised with " << nFiles << " file(s)." << std::endl;
	
	
	float retfitPVx, retfitPVy, retfitPVz;
	mtTree.SetBranchAddress("retfitPVx", &retfitPVx);
	mtTree.SetBranchAddress("retfitPVy", &retfitPVy);
	mtTree.SetBranchAddress("retfitPVz", &retfitPVz);
	
	for (Long64_t entry = 0; entry < 10/*lvTree.GetEntries()*/; ++entry)
	{
		mtTree.GetEntry(entry);
		std::cout << "Processing entry " << entry << "..." << std::endl;
		
		std::cout << "\t(x,y,z) = (" << retfitPVx << ", " << retfitPVy << ", " << retfitPVz << ")" << std::endl;
	}
	
	return 0;
}
