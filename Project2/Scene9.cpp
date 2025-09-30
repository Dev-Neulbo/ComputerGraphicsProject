//#include <GL/glut.h>
//#include <cmath>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")     
//
//const float PI = 3.14159265358979323846;
//float radius = 0.05;
//int numSegments = 100;
//
//void UN_playSound(const char* soundFile) {
//	    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
//	    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
//}
//
//void edge2() {
//	glColor3f(1.0f, 1.0f, 1.0f);
//	
//	glBegin(GL_LINES);
//	// 뉴스 테두리
//	glVertex3f(-0.8, -0.4, 0.0);
//	glVertex3f(0.8, -0.4, 0.0);
//
//	glVertex3f(-0.8, 0.1, 0.0);
//	glVertex3f(0.8, 0.1, 0.0);
//
//	glVertex3f(-0.8, 0.1, 0.0);
//	glVertex3f(-0.8, -0.4, 0.0);
//
//	glVertex3f(0.8, 0.1, 0.0);
//	glVertex3f(0.8, -0.4, 0.0);
//
//	glVertex3f(-0.3, 0.1, 0.0);
//	glVertex3f(-0.3, -0.4, 0.0);
//	glEnd();
//}
//
//
//void drawHalfCircleRight() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.7, -1.0, 0);
//	glVertex3f(-0.7, -1.1, 0);
//	float cx = -0.7;  // x축으로 이동
//	float cy = -1.05;  // y축으로 이동
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0부터 pi까지 각도
//		float x = radius * sin(theta) + cx;         // x좌표 계산
//		float y = radius * cos(theta) + cy;         // y좌표 계산
//		glVertex3f(x, y, 0);                      // 좌표 설정
//	}
//	glEnd();
//}
//
//void drawHalfCircleLeft() {
//	glBegin(GL_LINES);
//	float cx = -0.58;
//	float cy = -1.05;;
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0부터 pi까지 각도
//		float x = (-1) * radius * sin(theta) + cx;         // x좌표 계산
//		float y = (-1) * radius * cos(theta) + cy;         // y좌표 계산
//		glVertex3f(x, y, 0);                      // 좌표 설정
//	}
//	glEnd();
//}
//
//void drawU1() {
//	glBegin(GL_LINES);
//	float cx = -0.48;
//	float cy = -1.05;
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0부터 pi까지 각도
//		float x = (-1) * radius * cos(theta) + cx;         // x좌표 계산
//		float y = (-1) * radius * sin(theta) + cy;         // y좌표 계산
//		glVertex3f(x, y, 0);                      // 좌표 설정
//	}
//	glEnd();
//}
//void drawU2() {
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
//void U1() {
//	glBegin(GL_LINES);
//	float cx = -0.23;
//	float cy = -1.25;
//	for (int i = 0; i <= numSegments; ++i) {
//		float theta = i * (PI / numSegments);  // 0부터 pi까지 각도
//		float x = (-1) * radius * cos(theta) + cx;         // x좌표 계산
//		float y = (-1) * radius * sin(theta) + cy;         // y좌표 계산
//		glVertex3f(x, y, 0);                      // 좌표 설정
//	}
//	glEnd();
//}
//void U2() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.28, -1.0, 0);
//	glVertex3f(-0.28, -1.25, 0);
//
//	glVertex3f(-0.18, -1.0, 0);
//	glVertex3f(-0.18, -1.25, 0);
//	glEnd();
//
//}
//
//void N() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.16, -1.3, 0);
//	glVertex3f(-0.16, -1.0, 0);
//
//	glVertex3f(-0.16, -1.0, 0);
//	glVertex3f(-0.08, -1.3, 0);
//
//	glVertex3f(-0.08, -1.3, 0);
//	glVertex3f(-0.08, -1.0, 0);
//	glEnd();
//}
//
//void simpyo() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.05, -1.25, 0);
//	glVertex3f(-0.06, -1.3, 0);
//	glEnd();
//}
//
//void mi() {
//	glBegin(GL_LINES);
//	glVertex3f(-0.02, -1.02, 0);
//	glVertex3f(-0.02, -1.28, 0);
//
//	glVertex3f(-0.02, -1.28, 0);
//	glVertex3f(0.06, -1.28, 0);
//
//	glVertex3f(0.06, -1.28, 0);
//	glVertex3f(0.06, -1.02, 0);
//
//	glVertex3f(0.06, -1.02, 0);
//	glVertex3f(-0.02, -1.02, 0);
//
//	glVertex3f(0.08, -1.0, 0);
//	glVertex3f(0.08, -1.3, 0);
//	glEnd();
//}
//
//void Gun() {
//	glBegin(GL_LINES);
//	glVertex3f(0.1, -1.0, 0);
//	glVertex3f(0.18, -1.0, 0);
//
//	glVertex3f(0.18, -1.0, 0);
//	glVertex3f(0.18, -1.1, 0);
//
//	glVertex3f(0.09, -1.12, 0);
//	glVertex3f(0.19, -1.12, 0);
//
//	glVertex3f(0.14, -1.12, 0);
//	glVertex3f(0.14, -1.17, 0);
//
//	glVertex3f(0.09, -1.16, 0);
//	glVertex3f(0.09, -1.3, 0);
//
//	glVertex3f(0.09, -1.3, 0);
//	glVertex3f(0.19, -1.3, 0);
//	glEnd();
//}
//
//void Do() {
//	glBegin(GL_LINES);
//	glVertex3f(0.21, -1.0, 0);
//	glVertex3f(0.29, -1.0, 0);
//
//	glVertex3f(0.21, -1.0, 0);
//	glVertex3f(0.21, -1.15, 0);
//
//	glVertex3f(0.21, -1.15, 0);
//	glVertex3f(0.29, -1.15, 0);
//
//	glVertex3f(0.25, -1.15, 0);
//	glVertex3f(0.25, -1.3, 0);
//
//	glVertex3f(0.21, -1.3, 0);
//	glVertex3f(0.29, -1.3, 0);
//	glEnd();
//}
//
//void drawCham() {
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
//void drawJeon2() {
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
//void drawSeon() {
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
//void drawUN() {
//	glBegin(GL_LINES);
//	float cx = 0.69;
//	float cy = -1.05;
//	for (int i = 0; i <= 360; ++i) {
//		float theta = i * (PI / numSegments);  // 0부터 pi까지 각도
//		float x = radius * sin(theta) + cx;         // x좌표 계산
//		float y = radius * cos(theta) + cy;         // y좌표 계산
//		glVertex3f(x, y, 0);                      // 좌표 설정
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
//void init() {
//	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//	glOrtho(-1.5f, 1.5f, -1.5f, 1.5f, -1.0f, 1.0f);  // 2D 좌표 시스템 설정
//}
//
//void mydisplay() {
//	glClear(GL_COLOR_BUFFER_BIT);
//
//	glBegin(GL_LINES);
//
//	
//	edge2();
//	glTranslated(0.0f, 1.0f, 0.0f);
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
//	//뉴
//	drawKN();
//	drawKU();
//
//	//스
//	drawKS();
//	drawKEU();
//
//	//U
//	U1();
//	U2();
//
//	//N
//	N();
//
//	//,
//	simpyo();
//
//	//미
//	mi();
//
//	//군
//	Gun();
//
//	//도
//	Do();
//
//	//참
//	drawCham();
//
//	//전
//	drawJeon2();
//
//	//선
//	drawSeon();
//
//	//언
//	drawUN();
//
//	glEnd();
//	glFlush();
//	glutSwapBuffers();
//}
//
//void MyReshape(int NewWidth, int Newheight) {
//	glViewport(0, 0, NewWidth, Newheight);
//	glLoadIdentity();
//}
//
//void reshape(int w, int h) {
//	glViewport(0, 0, w, h);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // 2D 좌표 시스템
//	glMatrixMode(GL_MODELVIEW);
//}
//
//
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutCreateWindow("UN");
//	UN_playSound("미군참전.wav");
//
//	init();
//	glutDisplayFunc(mydisplay);
//	glutReshapeFunc(reshape);
//	glutMainLoop();
//	return 0;
//}