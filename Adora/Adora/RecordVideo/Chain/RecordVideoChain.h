

#ifndef _RECORDVIDEOCHAIN_H
#define _RECORDVIDEOCHAIN_H

class RecordVideoRequest;

class RecordVideoChain {

protected:
	RecordVideoChain *chain;

public:
	RecordVideoChain(RecordVideoChain *chain = nullptr);
	virtual ~RecordVideoChain() = 0;

	void setChain(RecordVideoChain *chain) { this->chain = chain; }

	virtual void request(RecordVideoRequest *request);

};

#endif //_RECORDVIDEOCHAIN_H
