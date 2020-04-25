#pragma once

// https://dojang.io/mod/page/view.php?id=721

// ��ū ���� ������
typedef enum _TOKEN_TYPE {
	TOKEN_STRING,    // ���ڿ� ��ū
	TOKEN_NUMBER,    // ���� ��ū
} TOKEN_TYPE;

// ��ū ����ü
typedef struct _TOKEN {
	TOKEN_TYPE type;    // ��ū ����
	union {             // �� ���� �� �� ������ ������ ���̹Ƿ� ����ü�� ����
		char* string;       // ���ڿ� ������
		double number;      // �Ǽ��� ����
	};
	bool isArray;       // ���� ��ū�� �迭���� ǥ��
} TOKEN;

#define TOKEN_COUNT 20    // ��ū�� �ִ� ����

// JSON ����ü
typedef struct _JSON {
	TOKEN tokens[TOKEN_COUNT];    // ��ū �迭
} JSON;