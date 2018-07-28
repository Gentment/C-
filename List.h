#ifndef  LIST_H
#define  LIST_H

class List
{
public:
	List(int size);
	~List();
	void ClearList();			//������Ա�
	bool ListEmpty();			//�ж��Ƿ�Ϊ��
	int ListLength();			//��ȡ���Ա�ĳ���
	bool GetElem(int i,int *e);  //��ȡָ��Ԫ��
	int LocateElem(int *e);		 //Ѱ�ҵ�һ������e������Ԫ�ص�λ��
	bool PriorElem(int *currentElem,int *preElem); //��ȡָ��Ԫ�ص�ǰ��
	bool NextElem(int *currentElem,int *nextElem); //��ȡָ��Ԫ�صĺ��
	void  ListTraverse();			//�������Ա�
	bool ListInsert(int i,int *e);//�ڵ�i��λ�ò���Ԫ��
	bool ListDelete(int i,int *e);//��ɾ����i��λ�õ�Ԫ��
private:
	int *m_pList;
	int m_iSize;
	int m_iLength;
};


#endif  //LIST_H