//#include "Scenes.h"
//#include <iostream>
//#include <GL/glut.h>
//#include <cstdio>  // ���� �����
//#include <cstdlib> // �޸� �Ҵ�
//
//#include <Windows.h>                // PlaySound Ȱ��ȭ
//#include <mmsystem.h>               // ȿ���� �ֱ�
//#pragma comment(lib,"winmm.lib")    // ���� �Ӽ� > ��� > ���� ���� > ���� ����
//									// �ʼ��� �ؾ� ���� ����˴ϴ� ������
////#define STB_IMAGE_IMPLEMENTATION
////#include "stb_image.h"
//
//using namespace std;
//GLuint texID; // �ؽ�ó ID�� ������ ���� ����
//int width4, height4; // �ؽ�ó�� ���� ����
//int display_change4 = 0; //display ü����
//
//float southCircleColors4[70][4];  // 70���� ���׶�� ����
//float northSphereColor4[4] = { 0.6f, 0.0f, 0.0f, 0.7f }; // ���� ��
//float southSphereColor4[4] = { 0.0f, 0.0f, 0.2f, 0.7f }; // ���� ��
//float whiteflagColor4[3] = { 1.0f, 1.0f, 1.0f }; //��� ���
//
//bool showNorthSpareBig4 = true; // ���� ���� ��ȭ�� ���׶��
//bool showNorthSpareMiddle4 = true; // ���� ���� �̵� ���׶��
//bool showNorthSpareSmall4 = true; // ���� ���� ���� ���׶��
//bool showSouthSpareBig4 = true; // ���� ���� ��ȭ�� ���׶��
//bool showSouthSpareMiddle4 = true; // ���� ���� �̵� ���׶��
//bool showSouthSpareSmall4 = true; // ���� ���� ���� ���׶��
//
//int currentSouthIndex4 = 0; // ���� ��ȭ ���� ���� ��ü�� ��ȣ
//
//void updateCircle4(int value) {		// ��ü ���� �� ���� ����
//	if (currentSouthIndex4 < 70) {
//		// R ���� ���ҽ�Ű�� B ���� ������Ŵ
//		for (int i = 0; i < 4; ++i) {
//			if (southCircleColors4[currentSouthIndex4][i] < northSphereColor4[i]) {
//				southCircleColors4[currentSouthIndex4][i] += 0.1f; // ����/���� ����
//				if (southCircleColors4[currentSouthIndex4][i] > northSphereColor4[i]) {
//					southCircleColors4[currentSouthIndex4][i] = northSphereColor4[i]; // �ʰ� ����
//				}
//			}
//			else if (southCircleColors4[currentSouthIndex4][i] > northSphereColor4[i]) {
//				southCircleColors4[currentSouthIndex4][i] -= 0.1f; // ����/���� ����
//				if (southCircleColors4[currentSouthIndex4][i] < northSphereColor4[i]) {
//					southCircleColors4[currentSouthIndex4][i] = northSphereColor4[i]; // �ʰ� ����
//				}
//			}
//		}
//
//		// ����� ������ ������ ���� ��ü�� ������ ����Ǿ����� Ȯ��
//		if (southCircleColors4[currentSouthIndex4][0] == northSphereColor4[0] &&
//			southCircleColors4[currentSouthIndex4][1] == northSphereColor4[1] &&
//			southCircleColors4[currentSouthIndex4][2] == northSphereColor4[2] &&
//			southCircleColors4[currentSouthIndex4][3] == northSphereColor4[3]) {
//			// ���� ��ü�� �̵�
//			currentSouthIndex4++;
//		}
//
//		glutPostRedisplay(); // ȭ�� ���� ��û
//		glutTimerFunc(5, updateCircle4, 0); // ��ȣ��
//	}
//}
//
//void wordtimer4(int value) {
//
//	display_change4++;	//// display_change�� �������� �ٸ� ȭ���� ǥ���ϵ��� ����
//	if (display_change4 > 3) {
//		display_change4 = 1; // ȭ���� ���������� ����
//	}
//
//	glutTimerFunc(10000, wordtimer4, 0); // 1�ʸ��� �ٽ� ȣ���Ͽ� �ִϸ��̼� ȿ��
//	glutPostRedisplay(); // ȭ�� ����
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
//	if (showSouthSpareBig4) {		// ���� ��ü (��ȭ��)
//		glColor4fv(southCircleColors4[next]); // �ش� ��ü�� ���� ���
//		glutSolidSphere(0.03, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareSmall4(int next) {
//	if (showSouthSpareSmall4) {
//		glColor4fv(southCircleColors4[next]); // �ش� ��ü�� ���� ���
//		glutSolidSphere(0.05, 50, 10);
//		glFlush();
//	}
//}
//
//void SouthspareMiddle4(int next) {
//	if (showSouthSpareMiddle4) {
//		glColor4fv(southCircleColors4[next]); // �ش� ��ü�� ���� ���
//		glutSolidSphere(0.075, 50, 10);
//		glFlush();
//	}
//}
//
//// BMP ������ �ε��ϴ� �Լ�
//unsigned char* LoadBMP4(const char* fileName, int* width, int* height) {
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
//	int dataSize = 3 * w * h; // �ȼ��� 3����Ʈ
//	unsigned char* data = new unsigned char[dataSize];
//
//	// BMP ������ �б�
//	fread(data, sizeof(unsigned char), dataSize, file);
//	fclose(file);
//
//	// BMP�� �Ʒ��ʺ��� �������� ����ǹǷ� ���� ���� �ʿ�
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
//void initTexture4(const char* fileName) {
//	unsigned char* image = LoadBMP4(fileName, &width4, &height4);
//	if (!image) {
//		std::cerr << "Failed to load BMP image." << std::endl;	// ��� Ȯ�ο�
//		return;
//	}
//
//	glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//	glGenTextures(1, &texID); // �ؽ�ó ID ����
//	glBindTexture(GL_TEXTURE_2D, texID); // �ؽ�ó ���ε�
//
//	// �ؽ�ó ����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// �ؽ�ó ������ ���ε�
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width4, height4, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
//
//	delete[] image; // �̹��� ������ ����
//}
//
//void playSound4(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC);
//}
//
//void drawBox4() {
//	glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//	glBindTexture(GL_TEXTURE_2D, texID);
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
//	glPopMatrix(); //
//
//	glDisable(GL_TEXTURE_2D); // �ؽ�ó ��Ȱ��ȭ
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
//	glPushMatrix(); // ���� ���� ����
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
//	glPopMatrix(); // ���� ���� ��
//
//	glPushMatrix();	// ���� ���� ����
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
//	glTranslatef(-0.17, -0.86, 0);	//���ֵ�
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
//	/// ��ȯ��
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
//	glPopMatrix();	// ���� ���� ��
//
//	glPushMatrix(); //���ȭ�� ��� ����
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
//	glClearColor(0.0, 0.0, 0.0, 1.0); // ���� ����
//	initTexture4("korea.bmp"); // �̹��� �߰�
//}
//
//int main(int argc, char** argv)
//{
//	for (int i = 0; i < 81; ++i) {
//		southCircleColors4[i][0] = 0.0f;  // ������ �ʱⰪ (���� ��ü�� ���������� ����)
//		southCircleColors4[i][1] = 0.0f;  // ��� �ʱⰪ
//		southCircleColors4[i][2] = 1.0f;  // �Ķ��� �ʱⰪ (���� ��ü�� �Ķ������� ����)
//		southCircleColors4[i][3] = 0.7f;  // ���� �ʱⰪ (������)
//	}
//
//	playSound4("�ϰ������̴�1.wav");
//
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(100, 100);
//	glutCreateWindow("Scene5");
//	init4();
//
//	glutDisplayFunc(Scene4);
//	glutTimerFunc(10000, wordtimer4, 0);	// ���� Ÿ�̸�
//	glutTimerFunc(5, updateCircle4, 0); // ���� ��ȭ Ÿ�̸� ����
//	glutReshapeFunc(reshape4);
//	
//	glutMainLoop();
//	return 0;
//}