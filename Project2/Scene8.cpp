//#include "Scenes.h"
//#include <iostream>
//#include <GL/glut.h>
//#include <cstdio>  // ���� �����
//#include <cstdlib> // �޸� �Ҵ�
//#include <Windows.h>                // PlaySound Ȱ��ȭ
//#include <mmsystem.h>               // ȿ���� �ֱ�
//#pragma comment(lib,"winmm.lib")    // ���� �Ӽ� > ��� > ���� ���� > ���� ���� �ʼ�
//									// �ʼ��� �ؾ� ���� ����˴ϴ� ������
////#define STB_IMAGE_IMPLEMENTATION
////#include "stb_image.h"
//
//
//using namespace std;
//GLuint texID8; // �ؽ�ó ID�� ������ ����
//int width8, height8; // �ؽ�ó�� ���� ����
//int display_change8 = 0; //display ü����
//
//float northCircleColors8[80][4];  // 80���� ���׶�� ����
//float northSphereColor8[4] = { 0.6f, 0.0f, 0.0f, 0.7f }; // ���� ��
//float southSphereColor8[4] = { 0.0f, 0.0f, 0.6f, 0.7f }; // ���� ��
//float whiteflagColor8[3] = { 1.0f, 1.0f, 1.0f }; //��� ���
//
//bool showNorthSpareBig8 = true; // ���� ���� ��ȭ�� ���׶��
//bool showNorthSpareMiddle8 = true; // ���� ���� �̵� ���׶��
//bool showNorthSpareSmall8 = true; // ���� ���� ���� ���׶��
//bool showSouthSpareBig8 = true; // ���� ���� ��ȭ�� ���׶��
//bool showSouthSpareMiddle8 = true; // ���� ���� �̵� ���׶��
//bool showSouthSpareSmall8 = true; // ���� ���� ���� ���׶��
//
//int currentNorthIndex8 = 0; // ���� ��ȭ ���� ���� ��ü�� ��ȣ
//
//void updateCircle8(int value) {		// ��ü ���� �� ���� ����
//	if (currentNorthIndex8 < 80) {
//		// R ���� ���ҽ�Ű�� B ���� ������Ŵ
//		if (northCircleColors8[currentNorthIndex8][0] > southSphereColor8[0]) {
//			northCircleColors8[currentNorthIndex8][0] -= 0.12f; // R �� ����
//			if (northCircleColors8[currentNorthIndex8][0] < southSphereColor8[0]) {
//				northCircleColors8[currentNorthIndex8][0] = southSphereColor8[0]; // �ʰ� ����
//			}
//		}
//
//		if (northCircleColors8[currentNorthIndex8][2] < southSphereColor8[2]) {
//			northCircleColors8[currentNorthIndex8][2] += 0.12f; // B �� ����
//			if (northCircleColors8[currentNorthIndex8][2] > southSphereColor8[2]) {
//				northCircleColors8[currentNorthIndex8][2] = southSphereColor8[2]; // �ʰ� ����
//			}
//		}
//
//		northCircleColors8[currentNorthIndex8][1] = southSphereColor8[1];
//		northCircleColors8[currentNorthIndex8][3] = southSphereColor8[3];
//
//		// ����� ������ ������ ���� ��ü�� ������ ����Ǿ����� Ȯ��
//		if (northCircleColors8[currentNorthIndex8][0] == southSphereColor8[0] &&
//			northCircleColors8[currentNorthIndex8][2] == southSphereColor8[2] &&
//			northCircleColors8[currentNorthIndex8][3] == southSphereColor8[3]) {
//			// ���� ��ü�� �̵�
//			currentNorthIndex8++;
//		}
//
//		glutPostRedisplay(); // ȭ�� ���� ��û
//		glutTimerFunc(10, updateCircle8, 0); // ��ȣ��
//	}
//}
//
//
//void wordtimer8(int value) {
//
//	display_change8++;	//// display_change�� �������� �ٸ� ȭ���� ǥ���ϵ��� ����
//	if (display_change8 > 3) {
//		display_change8 = 1; // ȭ���� ���������� ����
//	}
//
//	glutTimerFunc(10000, wordtimer8, 0); // 1�ʸ��� �ٽ� ȣ���Ͽ� �ִϸ��̼� ȿ��
//	glutPostRedisplay(); // ȭ�� ����
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
//	if (showNorthSpareBig8) {		// ���� ��ü (��ȭ��)
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
//	if (showSouthSpareBig8) {		// ���� ��ü (��ȭ��)
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
//// BMP ������ �ε��ϴ� �Լ�
//unsigned char* LoadBMP8(const char* fileName, int* width, int* height) {
//	FILE* file;
//	if (fopen_s(&file, fileName, "rb") != 0) { // BMP ���� ����
//		std::cerr << "Error: Could not open BMP file: " << fileName << std::endl;
//		return nullptr;
//	}
//
//	// BMP ���� ��� �б�
//	unsigned char header[54];
//	fread(header, sizeof(unsigned char), 54, file);
//
//	// �̹����� ���� ���̸� ����
//	int w = *(int*)&header[18];
//	int h = *(int*)&header[22];
//	*width = w;
//	*height = h;
//
//	// BMP ������ ũ�� ���
//	int dataSize = 3 * w * h; // RGB �����̹Ƿ� �ȼ��� 3����Ʈ
//	unsigned char* data = new unsigned char[dataSize];
//
//	// BMP ������ �б�
//	fread(data, sizeof(unsigned char), dataSize, file);
//	fclose(file);
//
//	// ���� ����
//	for (int i = 0; i < h / 2; ++i) {
//		for (int j = 0; j < w * 3; ++j) {
//			std::swap(data[i * w * 3 + j], data[(h - 1 - i) * w * 3 + j]);
//		}
//	}
//
//	return data;
//}
//
//// �ؽ�ó �ʱ�ȭ �Լ�
//void initTexture8(const char* fileName) {
//	unsigned char* image = LoadBMP8(fileName, &width8, &height8);
//	if (!image) {
//		std::cerr << "Failed to load BMP image." << std::endl;	// ��� Ȯ�ο�
//		return;
//	}
//
//	glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//	glGenTextures(1, &texID8); // �ؽ�ó ID ����
//	glBindTexture(GL_TEXTURE_2D, texID8); // �ؽ�ó ���ε�
//
//	// �ؽ�ó ����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// �ؽ�ó ������ ���ε�
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width8, height8, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//
//	delete[] image; // �̹��� ������ ����
//}
//
//void playSound8(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC);
//}
//
//void drawBox8() {
//	glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//	glBindTexture(GL_TEXTURE_2D, texID8);
//	glPushMatrix(); // ��� ����
//	glTranslatef(-0.08f, 0.0f, 0.0f); // �̹��� ���缭 �̵�
//
//	glBegin(GL_QUADS); // �簢�� �׸���
//	glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f, -1.0f, 0.0f); // ���� �ϴ�
//	glTexCoord2f(1.0f, 1.0f); glVertex3f(1.0f, -1.0f, 0.0f);  // ���� �ϴ�
//	glTexCoord2f(1.0f, 0.0f); glVertex3f(1.0f, 1.0f, 0.0f);   // ���� ���
//	glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, 1.0f, 0.0f);  // ���� ���
//	glEnd();
//
//	glPopMatrix();
//
//	glDisable(GL_TEXTURE_2D); // �ؽ�ó ��Ȱ��ȭ
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
//	glPushMatrix(); // ���� ���� ����
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
//	glPopMatrix(); // ���� ���� ��
//
//	glPushMatrix();	// ���� ���� ����
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
//	glTranslatef(-0.17, -0.86, 0);	//���ֵ�
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
//	/// ��ȯ��
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
//	glPopMatrix();	// ���� ���� ��
//
//	glPushMatrix(); //���ȭ�� ��� ����
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
//		northCircleColors8[i][0] = 1.0f;  // ������ �ʱⰪ (���� ��ü�� ���������� ����)
//		northCircleColors8[i][1] = 0.0f;  // ��� �ʱⰪ
//		northCircleColors8[i][2] = 0.0f;  // �Ķ��� �ʱⰪ (���� ��ü�� �Ķ������� ����)
//		northCircleColors8[i][3] = 0.7f;  // ���� �ʱⰪ (������)
//	}
//
//	glClearColor(0.0, 0.0, 0.0, 1.0); // ���� ����
//	initTexture8("korea.bmp"); // �̹��� �߰�
//
//	glutDisplayFunc(Scene8);
//	playSound8("����������1.wav");
//
//	glutTimerFunc(10, updateCircle8, 0); // ���� ��ȭ Ÿ�̸� ����
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