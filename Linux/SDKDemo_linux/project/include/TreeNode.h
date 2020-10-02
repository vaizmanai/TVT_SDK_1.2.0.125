
#ifndef _TREE_NODE_H_
#define _TREE_NODE_H_

#include "Typedef.h"
#include <stdio.h>
#include <string.h>

enum TREE_NODE_TYPE
{
	TREE_NODE_REGION,
	TREE_NODE_DEVICE,
	TREE_NODE_NONE,
};

class CRegionNode;
class CDeviceNode;
class CTreeNode;

//typedef int (*TRAVERSE_CALL)(CTreeNode *pNode, void *pUser);

class CTreeNode
{
public:
	CTreeNode(unsigned int index);
	virtual ~CTreeNode(void);

	CTreeNode *Parent();

	//���������ַ���
	CTreeNode *PrevSibling();
	CTreeNode *NextSibling();
	CTreeNode *FirstChild();

	//���ڵ����ͷ���
	CTreeNode *PrevSibling(const TREE_NODE_TYPE &nodeType);
	CTreeNode *NextSibling(const TREE_NODE_TYPE &nodeType);
	CTreeNode *FirstChild(const TREE_NODE_TYPE &nodeType);

	//����ָ����ŵĽڵ�
	CTreeNode *FindNode(unsigned int nodeIndex);

	//��ӡ�ɾ���ڵ�
	CTreeNode *InsertEndChild(const CTreeNode &node);
	CTreeNode *InsertBeforeChild(CTreeNode* pBeforeThis, const CTreeNode &node);
	BOOL RemoveChild(CTreeNode *pNode);
	void RemoveAllChild();

	//��ѯ�ڵ�����
	virtual TREE_NODE_TYPE NodeType() const;
	//�������లȫת��
	virtual CRegionNode *ToRegion(){return NULL;}
	virtual CDeviceNode *ToDevice(){return NULL;}
	unsigned int NodeIndex(){return m_nodeIndex;}

	//�����ݵķ���
	void *GetNodeData(){return m_pData;}
	void SetNodeData(void *pData){m_pData = pData;}

	void Traverse(int (*pTraverseCall)(CTreeNode *pNode, void *pUser), void *pUser);

protected:
	virtual CTreeNode *Clone() const;

protected:
	CTreeNode		*m_pParent;
	CTreeNode		*m_pPrevSibling;
	CTreeNode		*m_pNextSibling;
	CTreeNode		*m_pFirstChild;
	CTreeNode		*m_pLastChild;

	unsigned int	m_nodeIndex;
	void *			m_pData;
};

class CRegionNode : public CTreeNode
{
public:
	CRegionNode(const char *pRegionName, unsigned int index);
	~CRegionNode(void);

	TREE_NODE_TYPE NodeType() const{return TREE_NODE_REGION;}
	const char *RegionName() {return m_regionName;}
	void SetRegionName(const char *regionName){strcpy(m_regionName, regionName);}
	CRegionNode *ToRegion(){return this;}

protected:
	virtual CTreeNode *Clone() const;

private:
	char				m_regionName[64];
};

class CDeviceNode : public CTreeNode
{
public:
	CDeviceNode(const char *pDeviceName, unsigned int index);
	~CDeviceNode(void);

	TREE_NODE_TYPE NodeType() const{return TREE_NODE_DEVICE;}
	const char *DeviceName() {return m_deviceName;}
	void SetRegionName(const char *deviceName){strcpy(m_deviceName, deviceName);}
	CDeviceNode *ToDevice(){return this;}

	void SetNetInfo(unsigned short serverPort, const char *serverAddr);
	void SetUserInfo(const char *username, const char *passowrd);
	void SetChannelNum(unsigned short channelNum);

	BOOL GetNetInfo(unsigned short &serverPort, char *serverAddr);
	BOOL GetUserInfo(char *username, char *password);
	unsigned short GetChannelNum() const;

protected:
	virtual CTreeNode *Clone() const;

private:
	char				m_deviceName[64];

	unsigned short		m_serverPort;					//�豸�˿ں�
	unsigned short		m_channelNum;					//ͨ����Ŀ
	char				m_serverAddr[64];				//�豸�����ַ
	char				m_userName[64];					//��¼�豸���û���
	char				m_password[64];					//��¼�豸������
};

#endif

