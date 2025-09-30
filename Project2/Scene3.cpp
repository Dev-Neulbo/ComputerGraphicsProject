//#include <GL/glut.h>
//#include <cmath>
//#include <cstdio>  
//#include <cstdlib> 
//#include <iostream>
//#include <Windows.h>                // PlaySound Ȱ��ȭ
//#include <mmsystem.h>               // ȿ���� �ֱ�
//
//const float PI = 3.14159265358979323846;
//float radius = 0.05;
//int numSegments = 100;
//
//void playSound3(const char* soundFile) {
//	PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
//}
//
//
//void edge() {
//	glColor3f(0.0f, 0.0f, 0.0f);
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
//void drawHalfCircleRight() {
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex3f(-0.7, -1.0, 0);
//	glVertex3f(-0.7, -1.1, 0);
//	float cx = -0.7;  // x
//	float cy = -1.05;  // y
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = radius * sin(theta) + cx;         // x
//		float y = radius * cos(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawHalfCircleLeft() {
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	float cx = -0.58;
//	float cy = -1.05;
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * sin(theta) + cx;         // x
//		float y = (-1) * radius * cos(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawU1() {
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	float cx = -0.48;
//	float cy = -1.05;
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * cos(theta) + cx;         // x
//		float y = (-1) * radius * sin(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawU2() {
//	glColor3f(0.0f, 0.0f, 0.0f);
//	glBegin(GL_LINES);
//	glVertex3f(-0.53, -1.0, 0);
//	glVertex3f(-0.53, -1.05, 0);
//
//	glVertex3f(-0.43, -1.0, 0);
//	glVertex3f(-0.43, -1.05, 0);
//	glEnd();
//	glEnd();
//}
//
//void drawG() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.60, -1.05, 0);
//	glVertex3f(-0.55, -1.05, 0);
//
//	glVertex3f(-0.55, -1.05, 0);
//	glVertex3f(-0.55, -1.1, 0);
//	glEnd();
//}
//
//void drawKN() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.65, -1.15, 0.0);
//	glVertex3f(-0.65, -1.2, 0.0);
//
//	glVertex3f(-0.65, -1.2, 0.0);
//	glVertex3f(-0.6, -1.2, 0.0);
//	glEnd();
//}
//
//void drawKU() {
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
//void drawKS() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.5, -1.15, 0);
//	glVertex3f(-0.55, -1.25, 0);
//
//	glVertex3f(-0.5, -1.15, 0);
//	glVertex3f(-0.45, -1.25, 0);
//	glEnd();
//}
//
//void drawKEU() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.57, -1.3, 0);
//	glVertex3f(-0.43, -1.3, 0);
//	glEnd();
//}
//
//void drawKim() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.25, -1.0, 0);
//	glVertex3f(-0.18, -1.0, 0);
//
//	glVertex3f(-0.18, -1.0, 0);
//	glVertex3f(-0.25, -1.2, 0);
//
//	glVertex3f(-0.17, -1.2, 0);
//	glVertex3f(-0.17, -1.0, 0);
//
//	glVertex3f(-0.25, -1.25, 0);
//	glVertex3f(-0.25, -1.35, 0);
//
//	glVertex3f(-0.25, -1.35, 0);
//	glVertex3f(-0.17, -1.35, 0);
//
//	glVertex3f(-0.17, -1.35, 0);
//	glVertex3f(-0.17, -1.25, 0);
//
//	glVertex3f(-0.17, -1.25, 0);
//	glVertex3f(-0.25, -1.25, 0);
//	glEnd();
//}
//
//void drawJeo() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.14, -1.0, 0);
//	glVertex3f(-0.06, -1.0, 0);
//
//	glVertex3f(-0.1, -1.0, 0);
//	glVertex3f(-0.14, -1.2, 0);
//
//	glVertex3f(-0.1, -1.0, 0);
//	glVertex3f(-0.06, -1.2, 0);
//
//	glVertex3f(-0.07, -1.1, 0);
//	glVertex3f(-0.03, -1.1, 0);
//
//	glVertex3f(-0.03, -1.0, 0);
//	glVertex3f(-0.03, -1.2, 0);
//	glEnd();
//}
//
//void drawCircle() {
//	glBegin(GL_LINES);
//	float cx = -0.08;
//	float cy = -1.3;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * cos(theta) + cx;         // x
//		float y = (-1) * radius * sin(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawCircle2() {
//	glBegin(GL_LINES);
//	float cx = 0.04;
//	float cy = -1.05;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * cos(theta) + cx;         // x
//		float y = (-1) * radius * sin(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawKEU2() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.01, -1.15, 0);
//	glVertex3f(0.1, -1.15, 0);
//	glEnd();
//}
//
//void drawKN2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.01, -1.18, 0);
//	glVertex3f(0.01, -1.35, 0);
//
//	glVertex3f(0.01, -1.35, 0);
//	glVertex3f(0.09, -1.35, 0);
//	glEnd();
//}
//
//void drawshimpyo() {
//	glBegin(GL_LINES);
//	glVertex3f(0.12, -1.3, 0);
//	glVertex3f(0.11, -1.35, 0);
//	glEnd();
//}
//
//void drawCH() {
//	glBegin(GL_LINES);
//	glVertex3f(0.18, -1.03, 0);
//	glVertex3f(0.26, -1.03, 0);
//
//	glVertex3f(0.22, -1.0, 0);
//	glVertex3f(0.22, -1.03, 0);
//
//	glVertex3f(0.22, -1.03, 0);
//	glVertex3f(0.18, -1.13, 0);
//
//	glVertex3f(0.22, -1.03, 0);
//	glVertex3f(0.26, -1.13, 0);
//	glEnd();
//}
//
//void drawO() {
//	glBegin(GL_LINES);
//	glVertex3f(0.22, -1.09, 0);
//	glVertex3f(0.22, -1.16, 0);
//
//	glVertex3f(0.17, -1.16, 0);
//	glVertex3f(0.28, -1.16, 0);
//	glEnd();
//}
//
//void drawCircle3() {
//	glBegin(GL_LINES);
//	float cx = 0.225;
//	float cy = -1.28;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * cos(theta) + cx;         // x
//		float y = (-1) * radius * sin(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawG2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.3, -1.02, 0);
//	glVertex3f(0.39, -1.02, 0);
//
//	glVertex3f(0.39, -1.02, 0);
//	glVertex3f(0.39, -1.1, 0);
//	glEnd();
//}
//
//void drawO2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.34, -1.05, 0);
//	glVertex3f(0.34, -1.16, 0);
//
//	glVertex3f(0.3, -1.16, 0);
//	glVertex3f(0.4, -1.16, 0);
//	glEnd();
//}
//
//void drawCircle4() {
//	glBegin(GL_LINES);
//	float cx = 0.35;
//	float cy = -1.28;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = (-1) * radius * cos(theta) + cx;         // x
//		float y = (-1) * radius * sin(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawG3() {
//	glBegin(GL_LINES);
//	glVertex3f(0.42, -1.02, 0);
//	glVertex3f(0.5, -1.02, 0);
//
//	glVertex3f(0.5, -1.02, 0);
//	glVertex3f(0.42, -1.17, 0);
//	glEnd();
//}
//
//void drawYU() {
//	glBegin(GL_LINES);
//	glVertex3f(0.48, -1.06, 0);
//	glVertex3f(0.51, -1.06, 0);
//
//	glVertex3f(0.48, -1.13, 0);
//	glVertex3f(0.51, -1.13, 0);
//
//	glVertex3f(0.51, -1.02, 0);
//	glVertex3f(0.51, -1.17, 0);
//	glEnd();
//}
//
//void drawG4() {
//	glBegin(GL_LINES);
//	glVertex3f(0.42, -1.18, 0);
//	glVertex3f(0.51, -1.18, 0);
//
//	glVertex3f(0.51, -1.18, 0);
//	glVertex3f(0.51, -1.35, 0);
//	glEnd();
//}
//
//void drawS() {
//	glBegin(GL_LINES);
//	glVertex3f(0.58, -1.02, 0);
//	glVertex3f(0.55, -1.16, 0);
//
//	glVertex3f(0.58, -1.02, 0);
//	glVertex3f(0.61, -1.16, 0);
//	glEnd();
//}
//
//void drawUH() {
//	glBegin(GL_LINES);
//	glVertex3f(0.595, -1.09, 0);
//	glVertex3f(0.62, -1.09, 0);
//
//	glVertex3f(0.62, -1.02, 0);
//	glVertex3f(0.62, -1.16, 0);
//	glEnd();
//}
//
//void drawN() {
//	glBegin(GL_LINES);
//	glVertex3f(0.58, -1.18, 0);
//	glVertex3f(0.58, -1.35, 0);
//
//	glVertex3f(0.58, -1.35, 0);
//	glVertex3f(0.63, -1.35, 0);
//	glEnd();
//}
//
//void drawCircle5() {
//	glBegin(GL_LINES);
//	float cx = 0.68;
//	float cy = -1.07;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0���� pi ����
//		float x = radius * sin(theta) + cx;         // x
//		float y = radius * cos(theta) + cy;         // y
//		glVertex3f(x, y, 0);                      // ��ǥ ����
//	}
//	glEnd();
//}
//
//void drawUH2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.735, -1.06, 0);
//	glVertex3f(0.755, -1.06, 0);
//
//	glVertex3f(0.755, -1.02, 0);
//	glVertex3f(0.755, -1.16, 0);
//	glEnd();
//}
//
//void drawN2() {
//	glBegin(GL_LINES);
//	glVertex3f(0.68, -1.18, 0);
//	glVertex3f(0.68, -1.35, 0);
//
//	glVertex3f(0.68, -1.35, 0);
//	glVertex3f(0.755, -1.35, 0);
//	glEnd();
//}
//
//void drowgirl() {
//
//}
//
//void desk() {
//	glColor3f(0.8f, 0.52f, 0.25f);
//	glBegin(GL_QUADS);
//	glVertex3f(-2.0f, -0.5f, 0.0);
//	glVertex3f(2.0f, -0.5f, 0.0);
//	glVertex3f(2.0f, -0.85f, 0.0);
//	glVertex3f(-2.0f, -0.85f, 0.0);
//	glEnd();
//}
//
//void WindowColor() {
//	glColor3f(0.2f, 0.3f, 0.5f);
//	glBegin(GL_QUADS);
//	glVertex3f(-2.0f, 4.0f, 0.0);
//	glVertex3f(2.0f, 4.0f, 0.0);
//	glVertex3f(2.0f, -0.5f, 0.0);
//	glVertex3f(-2.0f, -0.5f, 0.0);
//	glEnd();
//}
//
//// �Ӹ� 
//void drawHead() {
//	glColor3f(1.0f, 0.8f, 0.6f); // �Ǻλ�
//	glPushMatrix();
//	glTranslatef(0.0f, 0.35f, 0.0f); // �Ӹ� ��ġ
//	glutSolidSphere(0.2, 20, 20); // �Ӹ�
//	glPopMatrix();
//}
//
//// �� 
//void drawEyes() {
//	glColor3f(0.0f, 0.0f, 0.0f); // ������
//	glPushMatrix();
//	// ���� ��
//	glTranslatef(-0.05f, 0.38f, 0.0f); // ���� �� ��ġ
//	glutSolidSphere(0.02, 10, 10); // ���� ��
//	glPopMatrix();
//
//	glPushMatrix();
//	// ������ ��
//	glTranslatef(0.05f, 0.38f, 0.0f); // ������ �� ��ġ
//	glutSolidSphere(0.02, 10, 10); // ������ ��
//	glPopMatrix();
//}
//int mouth = 1;
//void mouthtimer(int value) {
//	mouth++;
//	if (mouth > 10)
//		mouth = 1;
//
//	glutTimerFunc(10, mouthtimer, 0);
//	glutPostRedisplay();
//}
//
//// �� 
//
//void drawMouth() {
//	glColor3f(1.0f, 0.0f, 0.0f); // ������
//	glPushMatrix();
//	glTranslatef(0.0f, 0.23f, 0.0f); // �� ��ġ
//	if (mouth < 5) {
//		glBegin(GL_LINES);
//		glVertex2f(-0.05f, 0.0f);
//		glVertex2f(0.05f, 0.0f);
//	}
//	else {
//		glutSolidCube(0.06);
//	}
//	glEnd();
//	glPopMatrix();
//}
//
//// �� 
//void drawEars() {
//	glColor3f(1.0f, 0.8f, 0.6f); // �Ǻλ�
//	glPushMatrix();
//	// ���� ��
//	glTranslatef(-0.2f, 0.34f, 0.0f); // ��ġ ����
//	glScalef(0.05f, 0.1f, 0.1f); // ũ�� ����
//	glutSolidCube(1.0); // ���� ��
//	glPopMatrix();
//
//	glPushMatrix();
//	// ������ ��
//	glTranslatef(0.2f, 0.34f, 0.0f); // ��ġ ����
//	glScalef(0.05f, 0.1f, 0.1f); // ũ�� ����
//	glutSolidCube(1.0); // ������ ��
//	glPopMatrix();
//}
//
//// �� 
//void drawBody() {
//	glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
//	glPushMatrix();
//	glTranslatef(0.0f, -0.25f, 0.0f); // �� ��ġ
//	glScalef(0.3f, 0.5f, 1.0f); // �� ũ�� ����
//	glutSolidCube(1.0); // ��
//	glPopMatrix();
//}
//
//// ��
//void drawArms() {
//	glColor3f(1.0f, 0.8f, 0.6f); // �Ǻλ�
//	glPushMatrix();
//	// ���� ��
//	glTranslatef(-0.1f, -0.02f, 0.0f); // ��ġ ����
//	glScalef(0.2f, 0.1f, 1.0f); // �� ũ�� ����
//	glutSolidCube(1.0); // ���� ��
//	glPopMatrix();
//
//	glPushMatrix();
//	// ������ ��
//	glTranslatef(0.1f, 0.04f, 0.0f); // ��ġ ����
//	glScalef(0.2f, 0.1f, 1.0f); // �� ũ�� ����
//	glutSolidCube(1.0); // ������ ��
//	glPopMatrix();
//}
//
//// ����ũ
//void drawMicrophone() {
//	glColor3f(0.0f, 0.0f, 0.0f); // ������
//	glPushMatrix();
//	glTranslatef(0.0f, 0.06f, 0.0f); // ����ũ ��ġ
//	glScalef(0.05f, 0.2f, 0.05f); // ����ũ ũ�� ����
//	glutSolidCube(1.0); // ����ũ
//	glPopMatrix();
//
//	// ����ũ ���
//	glColor3f(0.5f, 0.5f, 0.5f); // ȸ��
//	glPushMatrix();
//	glTranslatef(0.0f, 0.13f, 0.0f); // ����ũ ��� ��ġ
//	glutSolidSphere(0.07, 10, 10); // ����ũ ���
//	glPopMatrix();
//}
//
//// �ǻ� 
//void drawClothes() {
//	glColor3f(1.0f, 0.0f, 0.0f); // ������
//	glPushMatrix();
//	glTranslatef(0.0f, 0.1f, 0.0f); // ��ġ ����
//	glScalef(0.3f, 0.2f, 1.0f); // �ǻ� ũ�� ����
//	glutSolidCube(1.0); // �ǻ�
//	glPopMatrix();
//}
//
//// �Ӹ�ī��
//void drawHair() {
//	glColor3f(0.3f, 0.2f, 0.1f); // ����
//	glPushMatrix();
//	glTranslatef(0.0f, 1.55f, 0.0f); // �Ӹ�ī�� ��ġ
//	glScalef(0.2f, 0.2f, 0.2f); // �Ӹ�ī�� ũ�� ����
//	glutSolidSphere(0.2, 20, 20); // �Ӹ�ī��
//	glPopMatrix();
//}
//
//// �Ƴ��
//void drawgirl() {
//	drawClothes();   // �ǻ�
//	drawHair();      // �Ӹ�ī��
//	drawHead();      // �Ӹ�
//	drawEyes();      // ��
//	drawMouth();     // ��
//	drawEars();      // ��
//	drawBody();      // ��
//	drawArms();      // ��
//	drawMicrophone(); // ����ũ
//}
//
//void Scene3() {
//	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glDisable(GL_TEXTURE_2D);
//
//	//�׵θ�
//	edge();
//
//	//D
//	drawHalfCircleRight();
//
//	//G
//	drawG();
//	drawHalfCircleLeft();
//
//	//U
//	drawU1();
//	drawU2();
//
//	//��
//	drawKN();
//	drawKU();
//
//	//��
//	drawKS();
//	drawKEU();
//
//	//��
//	drawKim();
//
//	//��
//	drawJeo();
//	drawCircle();
//
//	//��
//	drawCircle2();
//	drawKEU2();
//	drawKN2();
//
//	//,
//	drawshimpyo();
//
//	//��
//	drawCH();
//	drawO();
//	drawCircle3();
//
//	//��
//	drawG2();
//	drawO2();
//	drawCircle4();
//
//	//��
//	drawG3();
//	drawYU();
//	drawG4();
//
//	//��
//	drawS();
//	drawUH();
//	drawN();
//
//	//��
//	drawCircle5();
//	drawUH2();
//	drawN2();
//
//	//å��
//	desk();
//
//	//���� ��
//	WindowColor();
//
//	//�Ƴ��
//	drawgirl();
//
//	glFlush();
//	glutSwapBuffers();
//}
//
//void reshape3(GLint w, GLint h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	//glOrtho(-1.5f, 1.5f, -1.5f, 1.5f, -1.0f, 1.0f);
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
//	glMatrixMode(GL_MODELVIEW);
//}
//
//void init3() {
//	glEnable(GL_TEXTURE_2D);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//	glClearColor(0.3f, 0.15f, 0.05f, 1.0f);
//	glOrtho(-1.5f, 1.5f, -1.5f, 1.5f, -1.0f, 1.0f);
//
//}
//
//void initScene3() {
//
//	playSound3("�Ӻ�.wav");
//
//	glutDisplayFunc(Scene3);
//	glutReshapeFunc(reshape3);
//	init3();
//	glutTimerFunc(10, mouthtimer, 0);
//
//	glutMainLoop();
//}
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("Scene3");
//
//	initScene3();
//
//	glutMainLoop();
//	return 0;
//}