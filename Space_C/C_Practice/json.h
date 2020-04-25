#pragma once

// https://dojang.io/mod/page/view.php?id=721

// 토큰 종류 열거형
typedef enum _TOKEN_TYPE {
	TOKEN_STRING,    // 문자열 토큰
	TOKEN_NUMBER,    // 숫자 토큰
} TOKEN_TYPE;

// 토큰 구조체
typedef struct _TOKEN {
	TOKEN_TYPE type;    // 토큰 종류
	union {             // 두 종류 중 한 종류만 저장할 것이므로 공용체로 만듦
		char* string;       // 문자열 포인터
		double number;      // 실수형 숫자
	};
	bool isArray;       // 현재 토큰이 배열인지 표시
} TOKEN;

#define TOKEN_COUNT 20    // 토큰의 최대 개수

// JSON 구조체
typedef struct _JSON {
	TOKEN tokens[TOKEN_COUNT];    // 토큰 배열
} JSON;