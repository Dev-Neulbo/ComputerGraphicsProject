//#define STB_IMAGE_IMPLEMENTATION
//#include <GL/glut.h>
//#include "stb_image.h"
//#include <iostream>
//#include <cmath>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLuint JE_JP;
//const float JP_PI = 3.14159265358979323846;
//float JP_radius = 0.05;
//int JP_numSegments = 100;
//
//GLuint JP_loadTexture(const char* filename) {
//	int width, height, channels;
//	unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
//	if (!image) {
//		std::cerr << "Failed to load image: " << filename << std::endl;
//		exit(1);
//	}
//
//	GLuint texture;
//	glGenTextures(1, &texture);
//	glBindTexture(GL_TEXTURE_2D, texture);
//
//	// �ؽ�ó ���� ����
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//	// �ؽ�ó ������ ���ε�
//	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
//		channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
//
//	stbi_image_free(image); // �޸� ����
//	return texture;
//}
//
//void JP_edge2() {
//	glColor3f(1.0f, 1.0f, 1.0f);
//	glBegin(GL_LINES);
//	// ���� �׵θ�
//	glVertex3f(-0.8, -1.4, 0.0);
//	glVertex3f(0.8, -1.4, 0.0);
//
//	glVertex3f(-0.8, -0.9, 0.0);
//	glVertex3f(0.8, -0.9, 0.0);
//
//	glVertex3f(-0.8, -0.9, 0.0);
//	glVertex3f(-0.8, -1.4, 0.0);
//
//	glVertex3f(0.8, -0.9, 0.0);
//	glVertex3f(0.8, -1.4, 0.0);
//
//	glVertex3f(-0.3, -0.9, 0.0);
//	glVertex3f(-0.3, -1.4, 0.0);
//	glEnd();
//}
//
//
//void JP_drawHalfCircleRight() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.7, -1.0, 0);
//	glVertex3f(-0.7, -1.1, 0);
//	float cx = -0.7;  // x������ �̵�
//	float cy = -1.05;  // y������ �̵�
//	for (int i = 0; i <= JP_numSegments; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = JP_radius * sin(theta) + cx;         // x��ǥ ���
//		float y = JP_radius * cos(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void JP_drawHalfCircleLeft() {
//	glBegin(GL_LINES);
//	float cx = -0.58;
//	float cy = -1.05;;
//	for (int i = 0; i <= JP_numSegments; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = (-1) * JP_radius * sin(theta) + cx;         // x��ǥ ���
//		float y = (-1) * JP_radius * cos(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void JP_drawU1() {
//	glBegin(GL_LINES);
//	float cx = -0.48;
//	float cy = -1.05;
//	for (int i = 0; i <= JP_numSegments; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = (-1) * JP_radius * cos(theta) + cx;         // x��ǥ ���
//		float y = (-1) * JP_radius * sin(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//void JP_drawU2() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.53, -1.0, 0);
//	glVertex3f(-0.53, -1.05, 0);
//
//	glVertex3f(-0.43, -1.0, 0);
//	glVertex3f(-0.43, -1.05, 0);
//	glEnd();
//
//}
//
//void JP_drawG() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.60, -1.05, 0);
//	glVertex3f(-0.55, -1.05, 0);
//
//	glVertex3f(-0.55, -1.05, 0);
//	glVertex3f(-0.55, -1.1, 0);
//	glEnd();
//}
//
//void JP_drawKN() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.65, -1.15, 0.0);
//	glVertex3f(-0.65, -1.2, 0.0);
//
//	glVertex3f(-0.65, -1.2, 0.0);
//	glVertex3f(-0.6, -1.2, 0.0);
//	glEnd();
//}
//
//void JP_drawKU() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.67, -1.22, 0.0);
//	glVertex3f(-0.58, -1.22, 0.0);
//
//	glVertex3f(-0.64, -1.22, 0);
//	glVertex3f(-0.64, -1.32, 0);
//
//	glVertex3f(-0.61, -1.22, 0);
//	glVertex3f(-0.61, -1.32, 0);
//	glEnd();
//}
//
//void JP_drawKS() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.5, -1.15, 0);
//	glVertex3f(-0.55, -1.25, 0);
//
//	glVertex3f(-0.5, -1.15, 0);
//	glVertex3f(-0.45, -1.25, 0);
//	glEnd();
//}
//
//void JP_drawKEU() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.57, -1.3, 0);
//	glVertex3f(-0.43, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawJung() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.25, -1.1, 0);
//	glVertex3f(-0.25, -1.2, 0);
//
//	glVertex3f(-0.15, -1.1, 0);
//	glVertex3f(-0.15, -1.2, 0);
//
//	glVertex3f(-0.25, -1.1, 0);
//	glVertex3f(-0.15, -1.1, 0);
//
//	glVertex3f(-0.25, -1.2, 0);
//	glVertex3f(-0.15, -1.2, 0);
//
//	glVertex3f(-0.2, -1.0, 0);
//	glVertex3f(-0.2, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawShimpyo2() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.13, -1.3, 0);
//	glVertex3f(-0.14, -1.35, 0);
//	glEnd();
//}
//
//void JP_drawH() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.07, -1.0, 0);
//	glVertex3f(-0.07, -1.03, 0);
//
//	glVertex3f(-0.03, -1.03, 0);
//	glVertex3f(-0.11, -1.03, 0);
//	float cx = -0.07;
//	float cy = -1.1;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = JP_radius * sin(theta) + cx;         // x��ǥ ���
//		float y = JP_radius * cos(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void JP_drawA() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.01, -1.0, 0);
//	glVertex3f(-0.01, -1.15, 0);
//
//	glVertex3f(-0.01, -1.07, 0);
//	glVertex3f(0, -1.07, 0);
//	glEnd();
//}
//
//void JP_drawN() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.07, -1.2, 0);
//	glVertex3f(-0.07, -1.3, 0);
//
//	glVertex3f(-0.07, -1.3, 0);
//	glVertex3f(0, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawGUG() {
//	glBegin(GL_LINES);
//	glVertex3f(0.02, -1.0, 0);
//	glVertex3f(0.1, -1.0, 0);
//
//	glVertex3f(0.1, -1.0, 0);
//	glVertex3f(0.1, -1.1, 0);
//
//	glVertex3f(0.01, -1.15, 0);
//	glVertex3f(0.11, -1.15, 0);
//
//	glVertex3f(0.06, -1.15, 0);
//	glVertex3f(0.06, -1.18, 0);
//
//	glVertex3f(0.02, -1.18, 0);
//	glVertex3f(0.1, -1.18, 0);
//
//	glVertex3f(0.1, -1.18, 0);
//	glVertex3f(0.1, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawJeon() {
//	glBegin(GL_LINES);
//	glVertex3f(0.12, -1.0, 0);
//	glVertex3f(0.2, -1.0, 0);
//
//	glVertex3f(0.16, -1.0, 0);
//	glVertex3f(0.12, -1.15, 0);
//
//	glVertex3f(0.16, -1.0, 0);
//	glVertex3f(0.2, -1.15, 0);
//
//	glVertex3f(0.19, -1.07, 0);
//	glVertex3f(0.21, -1.07, 0);
//
//	glVertex3f(0.21, -1.0, 0);
//	glVertex3f(0.21, -1.15, 0);
//
//	glVertex3f(0.13, -1.16, 0);
//	glVertex3f(0.13, -1.3, 0);
//
//	glVertex3f(0.13, -1.3, 0);
//	glVertex3f(0.21, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawJaeng() {
//	glBegin(GL_LINES);
//	glVertex3f(0.22, -1.0, 0);
//	glVertex3f(0.3, -1.0, 0);
//
//	glVertex3f(0.26, -1.0, 0);
//	glVertex3f(0.22, -1.15, 0);
//
//	glVertex3f(0.26, -1.0, 0);
//	glVertex3f(0.3, -1.15, 0);
//
//	glVertex3f(0.31, -1.0, 0);
//	glVertex3f(0.31, -1.15, 0);
//
//	glVertex3f(0.31, -1.07, 0);
//	glVertex3f(0.33, -1.07, 0);
//
//	glVertex3f(0.33, -1.0, 0);
//	glVertex3f(0.33, -1.15, 0);
//
//	float cx = 0.285;
//	float cy = -1.25;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = JP_radius * sin(theta) + cx;         // x��ǥ ���
//		float y = JP_radius * cos(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void JP_drawCham() {
//	glBegin(GL_LINES);
//	glVertex3f(0.34, -1.02, 0);
//	glVertex3f(0.42, -1.02, 0);
//
//	glVertex3f(0.38, -1.0, 0);
//	glVertex3f(0.38, -1.02, 0);
//
//	glVertex3f(0.38, -1.02, 0);
//	glVertex3f(0.34, -1.15, 0);
//
//	glVertex3f(0.38, -1.02, 0);
//	glVertex3f(0.42, -1.15, 0);
//
//	glVertex3f(0.43, -1.0, 0);
//	glVertex3f(0.43, -1.15, 0);
//
//	glVertex3f(0.43, -1.07, 0);
//	glVertex3f(0.45, -1.07, 0);
//
//	glVertex3f(0.35, -1.18, 0);
//	glVertex3f(0.43, -1.18, 0);
//
//	glVertex3f(0.43, -1.18, 0);
//	glVertex3f(0.43, -1.3, 0);
//
//	glVertex3f(0.43, -1.3, 0);
//	glVertex3f(0.35, -1.3, 0);
//
//	glVertex3f(0.35, -1.3, 0);
//	glVertex3f(0.35, -1.18, 0);
//	glEnd();
//}
//
//void JP_drawJeon2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.44, -1.0, 0);
//	glVertex3f(0.52, -1.0, 0);
//
//	glVertex3f(0.48, -1.0, 0);
//	glVertex3f(0.44, -1.15, 0);
//
//	glVertex3f(0.48, -1.0, 0);
//	glVertex3f(0.52, -1.15, 0);
//
//	glVertex3f(0.51, -1.07, 0);
//	glVertex3f(0.53, -1.07, 0);
//
//	glVertex3f(0.53, -1.0, 0);
//	glVertex3f(0.53, -1.15, 0);
//
//	glVertex3f(0.45, -1.16, 0);
//	glVertex3f(0.45, -1.3, 0);
//
//	glVertex3f(0.45, -1.3, 0);
//	glVertex3f(0.53, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawSeon() {
//	glBegin(GL_LINES);
//	glVertex3f(0.58, -1.0, 0);
//	glVertex3f(0.54, -1.15, 0);
//
//	glVertex3f(0.58, -1.0, 0);
//	glVertex3f(0.62, -1.15, 0);
//
//	glVertex3f(0.61, -1.07, 0);
//	glVertex3f(0.63, -1.07, 0);
//
//	glVertex3f(0.63, -1.0, 0);
//	glVertex3f(0.63, -1.15, 0);
//
//	glVertex3f(0.55, -1.16, 0);
//	glVertex3f(0.55, -1.3, 0);
//
//	glVertex3f(0.55, -1.3, 0);
//	glVertex3f(0.63, -1.3, 0);
//	glEnd();
//}
//
//void JP_drawUN() {
//	float cx = 0.69;
//	float cy = -1.05;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (JP_PI / JP_numSegments);  // 0���� pi���� ����
//		float x = JP_radius * sin(theta) + cx;         // x��ǥ ���
//		float y = JP_radius * cos(theta) + cy;         // y��ǥ ���
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//	glBegin(GL_LINES);
//	glVertex3f(0.74, -1.05, 0);
//	glVertex3f(0.76, -1.05, 0);
//
//	glVertex3f(0.76, -1.0, 0);
//	glVertex3f(0.76, -1.15, 0);
//
//	glVertex3f(0.66, -1.16, 0);
//	glVertex3f(0.66, -1.3, 0);
//
//	glVertex3f(0.66, -1.3, 0);
//	glVertex3f(0.76, -1.3, 0);
//	glEnd();
//}
//void JP_init() {
//	glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//	glEnable(GL_BLEND);      // ���� Ȱ��ȭ
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // ���� ���� ����
//
//	glOrtho(-1.5f, 1.5f, -1.5f, 1.5f, -1.0f, 1.0f);
//	JE_JP = JP_loadTexture("JE_JP.png");
//
//
//	glLineWidth(3.0f); // ���� �β��� 3���� ����
//
//}
//
//void JP_mydisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBindTexture(GL_TEXTURE_2D, JE_JP);
//	glBegin(GL_QUADS);
//	glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.5f, -1.5f); // ���ϴ�
//	glTexCoord2f(1.0f, 1.0f); glVertex2f(1.5f, -1.5f);  // ���ϴ�
//	glTexCoord2f(1.0f, 0.0f); glVertex2f(1.5f, 1.5f);   // ����
//	glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.5f, 1.5f);  // �»��
//	glEnd();
//
//
//	glBegin(GL_LINES);
//	JP_edge2();
//
//	//D
//	JP_drawHalfCircleRight();
//
//	//G
//	JP_drawG();
//	JP_drawHalfCircleLeft();
//
//	//U
//	JP_drawU1();
//	JP_drawU2();
//
//	//��
//	JP_drawKN();
//	JP_drawKU();
//
//	//��
//	JP_drawKS();
//	JP_drawKEU();
//
//	//��
//	JP_drawJung();
//
//	//,
//	JP_drawShimpyo2();
//
//	//��
//	JP_drawH();
//	JP_drawA();
//	JP_drawN();
//
//	//��
//	JP_drawGUG();
//
//	//��
//	JP_drawJeon();
//
//	//��
//	JP_drawJaeng();
//
//	//��
//	JP_drawCham();
//
//	//��
//	JP_drawJeon2();
//
//	//��
//	JP_drawSeon();
//
//	//��
//	JP_drawUN();
//
//	glEnd();
//	glFlush();
//	glutSwapBuffers();
//}
//
//void JP_MyReshape(int NewWidth, int Newheight) {
//	glViewport(0, 0, NewWidth, Newheight);
//	glLoadIdentity();
//}
//
//void JP_reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.0, 1.0, -0.9, 0.9); // 2D ��ǥ �ý���
//	glMatrixMode(GL_MODELVIEW);
//}
//void JP_playSound(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Scene7");
//
//	JP_playSound("����2.wav");
//
//	JP_init();
//	glutDisplayFunc(JP_mydisplay);
//	glutReshapeFunc(JP_reshape);
//	glutMainLoop();
//	return 0;
//}