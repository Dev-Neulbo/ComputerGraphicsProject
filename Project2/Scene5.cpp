//#include "Scenes.h"
//#include <iostream>
//#include <GL/glut.h>
//#include <cstdio>  // 파일 입출력
//#include <cstdlib> // 메모리 할당
//
//#include <Windows.h>                // PlaySound 활성화
//#include <mmsystem.h>               // 효과음 넣기
//#pragma comment(lib,"winmm.lib")    // 구성 속성 > 고급 > 문자 집합 > 설정 안함
//									// 필수로 해야 정상 실행됩니다 교수님
////#define STB_IMAGE_IMPLEMENTATION
////#include "stb_image.h"
//
//using namespace std;
//GLuint texID; // 텍스처 ID를 저장할 전역 변수
//int width4, height4; // 텍스처의 폭과 높이
//int display_change4 = 0; //display 체인지
//
//float southCircleColors4[70][4];  // 70개의 동그라미 모음
//float northSphereColor4[4] = { 0.6f, 0.0f, 0.0f, 0.7f }; // 북쪽 구
//float southSphereColor4[4] = { 0.0f, 0.0f, 0.2f, 0.7f }; // 남쪽 구
//float whiteflagColor4[3] = { 1.0f, 1.0f, 1.0f }; //흰색 배경
//
//bool showNorthSpareBig4 = true; // 북한 진영 변화용 동그라미
//bool showNorthSpareMiddle4 = true; // 북한 진영 미들 동그라미
//bool showNorthSpareSmall4 = true; // 북한 진영 스몰 동그라미
//bool showSouthSpareBig4 = true; // 남한 진영 변화용 동그라미
//bool showSouthSpareMiddle4 = true; // 남한 진영 미들 동그라미
//bool showSouthSpareSmall4 = true; // 남한 진영 스몰 동그라미
//
//int currentSouthIndex4 = 0; // 현재 변화 중인 남한 구체의 번호
//
//void updateCircle4(int value) {		// 구체 색상 및 투명도 변경
//	if (currentSouthIndex4 < 70) {
//		// R 값을 감소시키고 B 값을 증가시킴
//		for (int i = 0; i < 4; ++i) {
//			if (southCircleColors4[currentSouthIndex4][i] < northSphereColor4[i]) {
//				southCircleColors4[currentSouthIndex4][i] += 0.1f; // 색상/투명도 증가
//				if (southCircleColors4[currentSouthIndex4][i] > northSphereColor4[i]) {
//					southCircleColors4[currentSouthIndex4][i] = northSphereColor4[i]; // 초과 방지
//				}
//			}
//			else if (southCircleColors4[currentSouthIndex4][i] > northSphereColor4[i]) {
//				southCircleColors4[currentSouthIndex4][i] -= 0.1f; // 색상/투명도 감소
//				if (southCircleColors4[currentSouthIndex4][i] < northSphereColor4[i]) {
//					southCircleColors4[currentSouthIndex4][i] = northSphereColor4[i]; // 초과 방지
//				}
//			}
//		}
//
//		// 색상과 투명도가 완전히 북한 구체의 값으로 변경되었는지 확인
//		if (southCircleColors4[currentSouthIndex4][0] == northSphereColor4[0] &&
//			southCircleColors4[currentSouthIndex4][1] == northSphereColor4[1] &&
//			southCircleColors4[currentSouthIndex4][2] == northSphereColor4[2] &&
//			southCircleColors4[currentSouthIndex4][3] == northSphereColor4[3]) {
//			// 다음 구체로 이동
//			currentSouthIndex4++;
//		}
//
//		glutPostRedisplay(); // 화면 갱신 요청
//		glutTimerFunc(5, updateCircle4, 0); // 재호출
//	}
//}
//
//void wordtimer4(int value) {
//
//	display_change4++;	//// display_change를 증가시켜 다른 화면을 표시하도록 변경
//	if (display_change4 > 3) {
//		display_change4 = 1; // 화면을 순차적으로 변경
//	}
//
//	glutTimerFunc(10000, wordtimer4, 0); // 1초마다 다시 호출하여 애니메이션 효과
//	glutPostRedisplay(); // 화면 갱신
//}
//
//void whiteflag4() {
//	glColor4fv(whiteflagColor4);
//	glutSolidSphere(0.001, 50, 10);
//	glFlush();
//}
//
//void NorthspareBig4() {
//	if (showNorthSpareBig4) {
//		glColor4fv(northSphereColor4);
//		glutSolidSphere(0.1, 50, 10);
//		glFlush();
//	}
//}
//
//void NorthspareSmall4() {
//	if (showNorthSpareSmall4) {
//		glColor4fv(northSphereColor4);
//		glutSolidSphere(0.05, 50, 10);
//		glFlush();
//	}
//}
//
//void NorthspareMiddle4() {
//	if (showNorthSpareMiddle4) {
//		glColor4fv(northSphereColor4);
//		glutSolidSphere(0.075, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareBig4(int next) {
//	if (showSouthSpareBig4) {		// 작은 구체 (변화용)
//		glColor4fv(southCircleColors4[next]); // 해당 구체의 색상 사용
//		glutSolidSphere(0.03, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareSmall4(int next) {
//	if (showSouthSpareSmall4) {
//		glColor4fv(southCircleColors4[next]); // 해당 구체의 색상 사용
//		glutSolidSphere(0.05, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareMiddle4(int next) {
//	if (showSouthSpareMiddle4) {
//		glColor4fv(southCircleColors4[next]); // 해당 구체의 색상 사용
//		glutSolidSphere(0.075, 50, 10);
//		glFlush();
//	}
//}
//
//// BMP 파일을 로드하는 함수
//unsigned char* LoadBMP4(const char* fileName, int* width, int* height) {
//	FILE* file;
//	if (fopen_s(&file, fileName, "rb") != 0) { // BMP 파일 열기
//		std::cerr << "Error: Could not open BMP file: " << fileName << std::endl;
//		return nullptr;
//	}
//
//	// BMP 파일 헤더 읽기
//	unsigned char header[54];
//	fread(header, sizeof(unsigned char), 54, file);
//
//	// 이미지의 폭과 높이를 읽음
//	int w = *(int*)&header[18];
//	int h = *(int*)&header[22];
//	*width = w;
//	*height = h;
//
//	// BMP 데이터 크기 계산
//	int dataSize = 3 * w * h; // 픽셀당 3바이트
//	unsigned char* data = new unsigned char[dataSize];
//
//	// BMP 데이터 읽기
//	fread(data, sizeof(unsigned char), dataSize, file);
//	fclose(file);
//
//	// BMP는 아래쪽부터 위쪽으로 저장되므로 상하 반전 필요
//	for (int i = 0; i < h / 2; ++i) {
//		for (int j = 0; j < w * 3; ++j) {
//			std::swap(data[i * w * 3 + j], data[(h - 1 - i) * w * 3 + j]);
//		}
//	}
//
//	return data;
//}
//
//// 텍스처 초기화 함수
//void initTexture4(const char* fileName) {
//	unsigned char* image = LoadBMP4(fileName, &width4, &height4);
//	if (!image) {
//		std::cerr << "Failed to load BMP image." << std::endl;	// 결과 확인용
//		return;
//	}
//
//	glEnable(GL_TEXTURE_2D); // 텍스처 활성화
//	glGenTextures(1, &texID); // 텍스처 ID 생성
//	glBindTexture(GL_TEXTURE_2D, texID); // 텍스처 바인딩
//
//	// 텍스처 설정
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// 텍스처 데이터 업로드
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//
//	delete[] image; // 이미지 데이터 삭제
//}
//
//void playSound4(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC);
//}
//
//void drawBox4() {
//	glEnable(GL_TEXTURE_2D); // 텍스처 활성화
//	glBindTexture(GL_TEXTURE_2D, texID);
//	glPushMatrix(); // 행렬 저장
//	glTranslatef(-0.08f, 0.0f, 0.0f); // 이미지 맞춰서 이동
//
//	glBegin(GL_QUADS); // 사각형 그리기
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 0.0f); // 좌측 하단
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 0.0f);  // 우측 하단
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);   // 우측 상단
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 0.0f);  // 좌측 상단
//	glEnd();
//
//	glPopMatrix(); //
//
//	glDisable(GL_TEXTURE_2D); // 텍스처 비활성화
//}
//
//void Scene4()
//{
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	drawBox4();
//
//	glDisable(GL_TEXTURE_2D);
//
//	glPushMatrix(); // 북한 진영 시작
//	glTranslatef(0.3, 0.8, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.2, 0.7, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.1, 0.68, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.15, 0.53, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.01, 0.42, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, 0.57, 0);
//	NorthspareSmall4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, 0.57, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.2, 0.42, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.38, 0.37, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.25, 0.25, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, 0.28, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, 0.15, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.25, 0.05, 0);
//	NorthspareBig4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, 0.0, 0);
//	NorthspareMiddle4();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, 0.09, 0);
//	NorthspareMiddle4();
//	glPopMatrix(); // 북한 진영 끝
//
//	glPushMatrix();	// 남한 진영 시작
//	glTranslatef(-0.13, -0.1, 0);
//	SouthspareBig4(0);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.15, 0);
//	SouthspareBig4(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.07, -0.1, 0);
//	SouthspareBig4(0);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.15, 0);
//	SouthspareBig4(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.07, 0);
//	SouthspareBig4(2);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.01, -0.01, 0);
//	SouthspareBig4(3);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.04, 0.0, 0);
//	SouthspareBig4(2);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, 0.04, 0);
//	SouthspareBig4(3);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, -0.01, 0);
//	SouthspareBig4(4);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.02, -0.06, 0);
//	SouthspareBig4(5);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.065, -0.05, 0);
//	SouthspareBig4(6);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.11, -0.05, 0);
//	SouthspareBig4(7);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, -0.21, 0);
//	SouthspareBig4(6);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.07, -0.21, 0);
//	SouthspareBig4(7);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.13, 0);
//	SouthspareBig4(8);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.18, 0);
//	SouthspareBig4(9);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.01, -0.11, 0);
//	SouthspareBig4(8);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.01, -0.16, 0);
//	SouthspareBig4(9);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.06, -0.1, 0);
//	SouthspareBig4(10);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.06, -0.15, 0);
//	SouthspareBig4(11);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.1, -0.1, 0);
//	SouthspareBig4(12);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.15, -0.09, 0);
//	SouthspareBig4(13);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.25, 0);
//	SouthspareBig4(12);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.3, 0);
//	SouthspareBig4(13);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, -0.25, 0);
//	SouthspareBig4(14);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.15, -0.25, 0);
//	SouthspareBig4(15);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.20, -0.25, 0);
//	SouthspareBig4(16);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.3, 0);
//	SouthspareBig4(17);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.3, 0);
//	SouthspareBig4(18);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.35, 0);
//	SouthspareBig4(19);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.34, 0);
//	SouthspareBig4(20);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.39, 0);
//	SouthspareBig4(21);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, -0.39, 0);
//	SouthspareBig4(22);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.44, 0);
//	SouthspareBig4(23);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.47, 0);
//	SouthspareBig4(24);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.16, -0.51, 0);
//	SouthspareBig4(25);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.18, -0.56, 0);
//	SouthspareBig4(26);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.13, -0.55, 0);
//	SouthspareBig4(27);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.13, -0.6, 0);
//	SouthspareBig4(28);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.15, -0.64, 0);
//	SouthspareBig4(29);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.51, 0);
//	SouthspareBig4(30);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.17, -0.86, 0);	//제주도
//	SouthspareBig4(31);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.51, 0);
//	SouthspareBig4(32);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.47, 0);
//	SouthspareBig4(33);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.56, 0);
//	SouthspareBig4(33);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.43, 0);
//	SouthspareBig4(34);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.6, 0);
//	SouthspareBig4(34);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.43, 0);
//	SouthspareBig4(35);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.49, 0);
//	SouthspareBig4(35);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.38, 0);
//	SouthspareBig4(36);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.53, 0);
//	SouthspareBig4(36);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.35, 0);
//	SouthspareBig4(37);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, -0.34, 0);
//	SouthspareBig4(38);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.58, 0);
//	SouthspareBig4(38);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, -0.4, 0);
//	SouthspareBig4(39);
//	glPopMatrix();
//
//
//	/// 변환점
//
//	glPushMatrix();
//	glTranslatef(0.05, -0.25, 0);
//	SouthspareMiddle4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.16, -0.18, 0);
//	SouthspareMiddle4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, -0.38, 0);
//	SouthspareMiddle4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.17, -0.3, 0);
//	SouthspareSmall4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.02, -0.47, 0);
//	SouthspareSmall4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.04, -0.56, 0);
//	SouthspareSmall4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.2, -0.39, 0);
//	SouthspareSmall4(80);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.14, -0.5, 0);
//	SouthspareMiddle4(80);
//	glPopMatrix();	// 남한 진영 끝
//
//	glPushMatrix(); //배경화면 흰색 유지
//	glTranslatef(0, 0, 0);
//	whiteflag4();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//void reshape4(GLint w, GLint h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 30.0);
//}
//
//void init4() {
//	glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색 설정
//	initTexture4("korea.bmp"); // 이미지 추가
//}
//
//int main(int argc, char** argv)
//{
//	for (int i = 0; i < 81; ++i) {
//		southCircleColors4[i][0] = 0.0f;  // 빨간색 초기값 (북한 구체는 빨간색으로 시작)
//		southCircleColors4[i][1] = 0.0f;  // 녹색 초기값
//		southCircleColors4[i][2] = 1.0f;  // 파란색 초기값 (북한 구체는 파란색으로 시작)
//		southCircleColors4[i][3] = 0.7f;  // 투명도 초기값 (반투명)
//	}
//
//	playSound4("북공격전이다1.wav");
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Scene5");
//	init4();
//
//	glutDisplayFunc(Scene4);
//	glutTimerFunc(10000, wordtimer4, 0);	// 월드 타이머
//	glutTimerFunc(5, updateCircle4, 0); // 색상 변화 타이머 시작
//	glutReshapeFunc(reshape4);
//	
//	glutMainLoop();
//	return 0;
//}