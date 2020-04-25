#ifndef _LINKLIST_H_
#define _LINKLIST_H_

struct _LINK_ONE_WAY
{
	int data;
	struct _LINK_ONE_WAY* next;
};

typedef struct _LINK_ONE_WAY LINK_ONE_WAY;
typedef struct _LINK_ONE_WAY* pLINK_ONE_WAY;


#else
#endif //_LINKLIST_H_