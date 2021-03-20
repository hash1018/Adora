

#include "RecordVideoChain.h"

RecordVideoChain::RecordVideoChain(RecordVideoChain *chain)
	:chain(chain) {

}

RecordVideoChain::~RecordVideoChain() {

}

void RecordVideoChain::request(RecordVideoRequest *request) {

	if (this->chain != nullptr)
		this->chain->request(request);
}

