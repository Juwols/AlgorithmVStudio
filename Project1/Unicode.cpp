// [GG]

#include <iostream>
#include <stdio.h>
#include <assert.h>

using namespace std;

/*
*
* �����ڵ�� 0x5D0 �̶�� �Ǿ������� D0 �� ���� �� ����Ʈ������ ��Ÿ���� ���̴�.
* UTF-8 �� ��ȯ�Ǹ� ����Ʈ ������ �ٲ��. �ϴ� � ���������� ����
* ���� 2 ����Ʈ�� �־��� ���� �ڵ忡�� �տ� 3 �ڿ� 2�� ������ 16 - 5 �� 11����Ʈ��
* ���� 0 ���� ���� ������ �ǰ� �� ���� ���� ���Ͽ� �°� ���ָ� �ȴ�.
*
* ���� 3 ����Ʈ��� 4, 6, 6 �� 16 ��Ʈ�� �տ��� ���� �����ͼ� ���
*
* 1110 ��������    10 ������������    10������������
*
* alfre unicode value 0x5D0 == U+05D0
*
* Two byte unicode is
*
* 0000 0101 1101 0000 => 11 bits
*
* two bits style is 110xxxxx, 10yyyyyy
*
* Now use valid 11 bit to xxxxx, yyyyy
*
* Then 110-10111 10-010000 is value
*      1101 0111 1001 0000
*      D    7    9    0
*
* 0x5D0 => D0 �� ù��° ����Ʈ�ΰ���
*
* ����� ���� �� ù ��° ����Ʈ�� 5 | 6 | 6 �̷��� ���� ������ ù ��° ����Ʈ�� ���� ���� ��� ��
*
* �� ����Ʈ ���� ���ϸ� ���� �������� 11�� ��Ʈ�� ������ ���̹Ƿ�
*
* 110 + 5bit, 10 + 6bit
*
* �� ����Ʈ ���� ���ϸ�,
*
* 1110 + 4bit, 10 + 6bit, 10 + 6bit = 16 ��Ʈ
*
* �� ����Ʈ�� �̸�
*
* 11110 + 3bit, 10 + 6bit, 10 + 6bit, 10 + 6bit = 21��Ʈ
*/

// int u = 0x5D0; // 12 bits 0101 1101 0000 (2bytes)
// int ucode = 0xC704; (3bytes_
// int ucode = 0x057E;
int ucode = 0xE0002;

int unicode(int u) {
	int r = 0;
	if (u >= 0 && u <= 0x7F) {
		r = u;
	}
	else if (u >= 0x80 && u <= 0x7FF) {
		int b2 = 0xC0;
		b2 = b2 | (u >> 6); //first 5
		int b1 = 0x80 | (u & ((1 << 6) - 1)); // last 6  <<======================== this is issue
		r = b2 << 8 | b1;
	}
	else if (u >= 0x800 && u <= 0xFFFF) {
		int tmp = (u & ((1 << 6) - 1));
		int b1 = 0x80;
		b1 = b1 | tmp;
		u = u >> 6;
		int b2 = 0x80;
		tmp = (u & ((1 << 6) - 1));
		u = u >> 6;
		b2 = b2 | tmp;
		int b3 = 0xE0;
		b3 = b3 | u;
		r = b3 << 16 | b2 << 8 | b1;
	}
	else {
		int tmp = (u & ((1 << 6) - 1));
		int b1 = 0x80;
		b1 = b1 | tmp;
		u = u >> 6;
		int b2 = 0x80;
		tmp = (u & ((1 << 6) - 1));
		u = u >> 6;
		b2 = b2 | tmp;

		int b3 = 0x80;
		tmp = (u & ((1 << 6) - 1));
		u = u >> 6;
		b3 = b3 | tmp;

		int b4 = 0xF0;
		b4 = b4 | u;

		r = b4 << 24 | b3 << 16 | b2 << 8 | b1;
	}
	return r;
}

int unicodeTest() {
	int r = unicode(ucode);
	printf("unicode2: %0X\n", r);
	return 0;
}
