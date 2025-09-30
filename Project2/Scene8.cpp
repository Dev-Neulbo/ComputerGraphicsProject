//#include "Scenes.h"
//#include <iostream>
//#include <GL/glut.h>
//#include <cstdio>  // 파일 입출력
//#include <cstdlib> // 메모리 할당
//#include <Windows.h>                // PlaySound 활성화
//#include <mmsystem.h>               // 효과음 넣기
//#pragma comment(lib,"winmm.lib")    // 구성 속성 > 고급 > 문자 집합 > 설정 안함 필수
//									// 필수로 해야 정상 실행됩니다 교수님
////#define STB_IMAGE_IMPLEMENTATION
////#include "stb_image.h"
//
//
//using namespace std;
//GLuint texID8; // 텍스처 ID를 저장할 변수
//int width8, height8; // 텍스처의 폭과 높이
//int display_change8 = 0; //display 체인지
//
//float northCircleColors8[80][4];  // 80개의 동그라미 모음
//float northSphereColor8[4] = { 0.6f, 0.0f, 0.0f, 0.7f }; // 북쪽 구
//float southSphereColor8[4] = { 0.0f, 0.0f, 0.6f, 0.7f }; // 남쪽 구
//float whiteflagColor8[3] = { 1.0f, 1.0f, 1.0f }; //흰색 배경
//
//bool showNorthSpareBig8 = true; // 북한 진영 변화용 동그라미
//bool showNorthSpareMiddle8 = true; // 북한 진영 미들 동그라미
//bool showNorthSpareSmall8 = true; // 북한 진영 스몰 동그라미
//bool showSouthSpareBig8 = true; // 남한 진영 변화용 동그라미
//bool showSouthSpareMiddle8 = true; // 남한 진영 미들 동그라미
//bool showSouthSpareSmall8 = true; // 남한 진영 스몰 동그라미
//
//int currentNorthIndex8 = 0; // 현재 변화 중인 남한 구체의 번호
//
//void updateCircle8(int value) {		// 구체 색상 및 투명도 변경
//	if (currentNorthIndex8 < 80) {
//		// R 값을 감소시키고 B 값을 증가시킴
//		if (northCircleColors8[currentNorthIndex8][0] > southSphereColor8[0]) {
//			northCircleColors8[currentNorthIndex8][0] -= 0.12f; // R 값 감소
//			if (northCircleColors8[currentNorthIndex8][0] < southSphereColor8[0]) {
//				northCircleColors8[currentNorthIndex8][0] = southSphereColor8[0]; // 초과 방지
//			}
//		}
//
//		if (northCircleColors8[currentNorthIndex8][2] < southSphereColor8[2]) {
//			northCircleColors8[currentNorthIndex8][2] += 0.12f; // B 값 증가
//			if (northCircleColors8[currentNorthIndex8][2] > southSphereColor8[2]) {
//				northCircleColors8[currentNorthIndex8][2] = southSphereColor8[2]; // 초과 방지
//			}
//		}
//
//		northCircleColors8[currentNorthIndex8][1] = southSphereColor8[1];
//		northCircleColors8[currentNorthIndex8][3] = southSphereColor8[3];
//
//		// 색상과 투명도가 완전히 남쪽 구체의 값으로 변경되었는지 확인
//		if (northCircleColors8[currentNorthIndex8][0] == southSphereColor8[0] &&
//			northCircleColors8[currentNorthIndex8][2] == southSphereColor8[2] &&
//			northCircleColors8[currentNorthIndex8][3] == southSphereColor8[3]) {
//			// 다음 구체로 이동
//			currentNorthIndex8++;
//		}
//
//		glutPostRedisplay(); // 화면 갱신 요청
//		glutTimerFunc(10, updateCircle8, 0); // 재호출
//	}
//}
//
//
//void wordtimer8(int value) {
//
//	display_change8++;	//// display_change를 증가시켜 다른 화면을 표시하도록 변경
//	if (display_change8 > 3) {
//		display_change8 = 1; // 화면을 순차적으로 변경
//	}
//
//	glutTimerFunc(10000, wordtimer8, 0); // 1초마다 다시 호출하여 애니메이션 효과
//	glutPostRedisplay(); // 화면 갱신
//}
//
//void whiteflag8() {
//	glColor4fv(whiteflagColor8);
//	glutSolidSphere(0.001, 50, 10);
//	glFlush();
//}
//
//void NorthspareBigg8(int next) {
//	if (showNorthSpareBig8) {
//		glColor4fv(northCircleColors8[next]);
//		glutSolidSphere(0.1, 50, 10);
//		glFlush();
//	}
//}
//
//void NorthspareBig8(int next) {
//	if (showNorthSpareBig8) {		// 작은 구체 (변화용)
//		glColor4fv(northCircleColors8[next]);
//		glutSolidSphere(0.03, 50, 10);
//		glFlush();
//	}
//}
//
//void NorthspareSmall8(int next) {
//	if (showNorthSpareSmall8) {
//		glColor4fv(northCircleColors8[next]);
//		glutSolidSphere(0.05, 50, 10);
//		glFlush();
//	}
//}
//
//void NorthspareMiddle8(int next) {
//	if (showNorthSpareMiddle8) {
//		glColor4fv(northCircleColors8[next]);
//		glutSolidSphere(0.075, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareBig8() {
//	if (showSouthSpareBig8) {		// 작은 구체 (변화용)
//		glColor4fv(southSphereColor8);
//		glutSolidSphere(0.03, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareSmall8() {
//	if (showSouthSpareSmall8) {
//		glColor4fv(southSphereColor8);
//		glutSolidSphere(0.05, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareMiddle8() {
//	if (showSouthSpareMiddle8) {
//		glColor4fv(southSphereColor8);
//		glutSolidSphere(0.075, 50, 10);
//		glFlush();
//	}
//}
//
//// BMP 파일을 로드하는 함수
//unsigned char* LoadBMP8(const char* fileName, int* width, int* height) {
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
//	int dataSize = 3 * w * h; // RGB 포맷이므로 픽셀당 3바이트
//	unsigned char* data = new unsigned char[dataSize];
//
//	// BMP 데이터 읽기
//	fread(data, sizeof(unsigned char), dataSize, file);
//	fclose(file);
//
//	// 상하 반전
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
//void initTexture8(const char* fileName) {
//	unsigned char* image = LoadBMP8(fileName, &width8, &height8);
//	if (!image) {
//		std::cerr << "Failed to load BMP image." << std::endl;	// 결과 확인용
//		return;
//	}
//
//	glEnable(GL_TEXTURE_2D); // 텍스처 활성화
//	glGenTextures(1, &texID8); // 텍스처 ID 생성
//	glBindTexture(GL_TEXTURE_2D, texID8); // 텍스처 바인딩
//
//	// 텍스처 설정
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// 텍스처 데이터 업로드
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width8, height8, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//
//	delete[] image; // 이미지 데이터 삭제
//}
//
//void playSound8(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC);
//}
//
//void drawBox8() {
//	glEnable(GL_TEXTURE_2D); // 텍스처 활성화
//	glBindTexture(GL_TEXTURE_2D, texID8);
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
//	glPopMatrix();
//
//	glDisable(GL_TEXTURE_2D); // 텍스처 비활성화
//}
//
//void Scene8()
//{
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	drawBox8();
//
//	glDisable(GL_TEXTURE_2D);
//
//	glPushMatrix(); // 북한 진영 시작
//	glTranslatef(0.3, 0.8, 0);
//	NorthspareMiddle8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.2, 0.7, 0);
//	NorthspareMiddle8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.1, 0.68, 0);
//	NorthspareMiddle8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.15, 0.53, 0);
//	NorthspareBigg8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.01, 0.42, 0);
//	NorthspareBigg8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, 0.57, 0);
//	NorthspareSmall8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, 0.57, 0);
//	NorthspareMiddle8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.2, 0.42, 0);
//	NorthspareBigg8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.38, 0.37, 0);
//	NorthspareBigg8(79);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.25, 0.25, 0);
//	NorthspareBigg8(51);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, 0.28, 0);
//	NorthspareMiddle8(50);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, 0.15, 0);
//	NorthspareMiddle8(49);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.25, 0.05, 0);
//	NorthspareBigg8(47);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, 0.0, 0);
//	NorthspareMiddle8(45);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, 0.09, 0);
//	NorthspareMiddle8(43);
//	glPopMatrix(); // 북한 진영 끝
//
//	glPushMatrix();	// 남한 진영 시작
//	glTranslatef(-0.13, -0.1, 0);
//	NorthspareBig8(40);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.15, 0);
//	NorthspareBig8(39);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.07, -0.1, 0);
//	NorthspareBig8(40);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.15, 0);
//	NorthspareBig8(39);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.07, 0);
//	NorthspareBig8(38);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.01, -0.01, 0);
//	NorthspareBig8(37);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.04, 0.0, 0);
//	NorthspareBig8(38);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, 0.04, 0);
//	NorthspareBig8(37);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, -0.01, 0);
//	NorthspareBig8(36);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.02, -0.06, 0);
//	NorthspareBig8(35);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.065, -0.05, 0);
//	NorthspareBig8(34);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.11, -0.05, 0);
//	NorthspareBig8(33);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.11, -0.21, 0);
//	NorthspareBig8(34);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.07, -0.21, 0);
//	NorthspareBig8(33);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.13, 0);
//	NorthspareBig8(32);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.18, 0);
//	NorthspareBig8(31);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.01, -0.11, 0);
//	NorthspareBig8(30);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.01, -0.16, 0);
//	NorthspareBig8(29);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.06, -0.1, 0);
//	NorthspareBig8(28);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.06, -0.15, 0);
//	NorthspareBig8(27);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.1, -0.1, 0);
//	NorthspareBig8(26);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.15, -0.09, 0);
//	NorthspareBig8(24);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.25, 0);
//	NorthspareBig8(25);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.3, 0);
//	NorthspareBig8(24);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, -0.25, 0);
//	NorthspareBig8(23);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.15, -0.25, 0);
//	NorthspareBig8(22);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.20, -0.25, 0);
//	NorthspareBig8(21);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.3, 0);
//	NorthspareBig8(21);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.3, 0);
//	NorthspareBig8(20);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.35, 0);
//	NorthspareBig8(19);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.34, 0);
//	NorthspareBig8(17);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.39, 0);
//	NorthspareBig8(18);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.1, -0.39, 0);
//	NorthspareBig8(17);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.44, 0);
//	NorthspareBig8(16);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.14, -0.47, 0);
//	NorthspareBig8(16);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.16, -0.51, 0);
//	NorthspareBig8(15);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.18, -0.56, 0);
//	NorthspareBig8(14);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.13, -0.55, 0);
//	NorthspareBig8(13);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.13, -0.6, 0);
//	NorthspareBig8(12);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.15, -0.64, 0);
//	NorthspareBig8(11);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.12, -0.51, 0);
//	NorthspareBig8(10);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.17, -0.86, 0);	//제주도
//	NorthspareBig8(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.51, 0);
//	NorthspareBig8(8);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.47, 0);
//	NorthspareBig8(7);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.56, 0);
//	NorthspareBig8(6);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.08, -0.43, 0);
//	NorthspareBig8(6);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.09, -0.6, 0);
//	NorthspareBig8(4);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.43, 0);
//	NorthspareBig8(5);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.49, 0);
//	NorthspareBig8(4);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.05, -0.38, 0);
//	NorthspareBig8(3);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.53, 0);
//	NorthspareBig8(3);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.04, -0.35, 0);
//	NorthspareBig8(2);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, -0.34, 0);
//	NorthspareBig8(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(-0.03, -0.58, 0);
//	NorthspareBig8(1);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.0, -0.4, 0);
//	NorthspareBig8(0);
//	glPopMatrix();
//
//
//	/// 변환점
//
//	glPushMatrix();
//	glTranslatef(0.05, -0.25, 0);
//	SouthspareMiddle8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.16, -0.18, 0);
//	SouthspareMiddle8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.08, -0.38, 0);
//	SouthspareMiddle8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.17, -0.3, 0);
//	SouthspareSmall8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.02, -0.47, 0);
//	SouthspareSmall8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.04, -0.56, 0);
//	SouthspareSmall8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.2, -0.39, 0);
//	SouthspareSmall8();
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslatef(0.14, -0.5, 0);
//	SouthspareMiddle8();
//	glPopMatrix();	// 남한 진영 끝
//
//	glPushMatrix(); //배경화면 흰색 유지
//	glTranslatef(0, 0, 0);
//	whiteflag8();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//void reshape8(GLint w, GLint h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 30.0);
//}
//
//void initScene8() {
//
//	for (int i = 0; i < 80; ++i) {
//		northCircleColors8[i][0] = 1.0f;  // 빨간색 초기값 (북한 구체는 빨간색으로 시작)
//		northCircleColors8[i][1] = 0.0f;  // 녹색 초기값
//		northCircleColors8[i][2] = 0.0f;  // 파란색 초기값 (북한 구체는 파란색으로 시작)
//		northCircleColors8[i][3] = 0.7f;  // 투명도 초기값 (반투명)
//	}
//
//	glClearColor(0.0, 0.0, 0.0, 1.0); // 배경색 설정
//	initTexture8("korea.bmp"); // 이미지 추가
//
//	glutDisplayFunc(Scene8);
//	playSound8("전선을간다1.wav");
//
//	glutTimerFunc(10, updateCircle8, 0); // 색상 변화 타이머 시작
//	glutReshapeFunc(reshape8);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene8");
//
//    initScene8();
//    
//    glutMainLoop();
//    return 0;
//}