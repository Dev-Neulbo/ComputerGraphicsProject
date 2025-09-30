//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <cmath>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//
//float Switch_heightScale = 0.0f;  // 초기 높이를 1로 설정
//float Switch_fingerDown = 0.0f;
//bool Switch_shrinking = true;     // 크기가 줄어들고 있는지 여부
//float Switch_M_PI = 3.14;
//
//void Switch_Bombswitch() {
//
//    glColor3f(0.5f, 0.5f, 0.5f);  // 철색
//
//    glBegin(GL_POLYGON);
//    glVertex3f(0.4, 0, 0);
//    glVertex3f(-0.4, 0, 0);
//    glVertex3f(-0.6, -0.4, 0);
//    glVertex3f(0.2, -0.4, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.4, 0, 0);
//    glVertex3f(-0.6, -0.4, 0);
//    glVertex3f(-0.6, -0.7, 0);
//    glVertex3f(-0.4, -0.3, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(0.4, 0, 0);
//    glVertex3f(0.2, -0.4, 0);
//    glVertex3f(0.2, -0.7, 0);
//    glVertex3f(0.4, -0.3, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.6, -0.4, 0);
//    glVertex3f(0.2, -0.7, 0);
//    glVertex3f(-0.6, -0.7, 0);
//    glVertex3f(0.4, -0.3, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.6, -0.7, 0);
//    glVertex3f(0.2, -0.3, 0);
//    glVertex3f(0.2, -0.7, 0);
//    glVertex3f(0.4, -0.3, 0);
//    glEnd();
//}
//
//void Switch_Line() {
//    glLineWidth(2.0f);
//    glColor3f(0, 0, 0);
//    glBegin(GL_LINES);
//
//    glVertex3f(0.4, 0, 0);
//    glVertex3f(-0.4, 0, 0);
//
//    glVertex3f(-0.4, 0, 0);
//    glVertex3f(-0.6, -0.4, 0);
//
//    glVertex3f(0.4, 0, 0);
//    glVertex3f(0.2, -0.4, 0);
//
//    glVertex3f(-0.6, -0.4, 0);
//    glVertex3f(0.2, -0.4, 0);
//
//    glVertex3f(-0.6, -0.4, 0);
//    glVertex3f(-0.6, -0.7, 0);
//
//    glVertex3f(0.2, -0.4, 0);
//    glVertex3f(0.2, -0.7, 0);
//
//    glVertex3f(0.4, 0, 0);
//    glVertex3f(0.4, -0.3, 0);
//
//    glVertex3f(-0.6, -0.7, 0);
//    glVertex3f(0.2, -0.7, 0);
//
//    glVertex3f(0.4, -0.3, 0);
//    glVertex3f(0.2, -0.7, 0);
//    glEnd();
//}
//
//void Switch_BombSwitch2() {
//    glColor3f(1.0f, 0.0f, 0.0f);  // 빨간색
//
//
//    glBegin(GL_POLYGON);
//    glVertex3f(0.2, 0.05 + Switch_heightScale, 0);
//    glVertex3f(-0.2, 0.05 + Switch_heightScale, 0);
//    glVertex3f(-0.3, -0.15 + Switch_heightScale, 0);
//    glVertex3f(0.1, -0.15 + Switch_heightScale, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.2, 0.05 + Switch_heightScale, 0);
//    glVertex3f(-0.3, -0.15 + Switch_heightScale, 0);
//    glVertex3f(-0.3, -0.3, 0);
//    glVertex3f(-0.2, -0.1 + Switch_heightScale, 0);
//    glEnd();
//
//    glBegin(GL_POLYGON);
//    glVertex3f(0.2, 0.05 + Switch_heightScale, 0);
//    glVertex3f(0.1, -0.15 + Switch_heightScale, 0);
//    glVertex3f(0.1, -0.3, 0);
//    glVertex3f(0.2, -0.1, 0);
//    glEnd();
//
//
//    glBegin(GL_POLYGON);
//    glVertex3f(-0.3, -0.3, 0);
//    glVertex3f(0.1, -0.3, 0);
//    glVertex3f(0.1, -0.15 + Switch_heightScale, 0);
//    glVertex3f(-0.3, -0.15 + Switch_heightScale, 0);
//    glEnd();
//}
//void Switch_drawSemiCircle(float centerX, float centerY, float radius) {
//    glBegin(GL_TRIANGLE_FAN);
//    glVertex2f(centerX, centerY); // 중심점
//    for (int angle = 180; angle <= 360; ++angle) { // 180도 ~ 360도
//        float rad = angle * Switch_M_PI / 180.0f; // 각도를 라디안으로 변환
//        float x = centerX + radius * cos(rad);
//        float y = centerY + radius * sin(rad);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//void Switch_drawNail(float x, float y, float width, float height) {
//    glColor3f(1.0f, 0.9f, 0.9f); // 연한 흰색
//    glBegin(GL_QUADS);
//    glVertex2f(x, y);                     // 왼쪽 아래
//    glVertex2f(x + width, y);             // 오른쪽 아래
//    glVertex2f(x + width, y + height);    // 오른쪽 위
//    glVertex2f(x, y + height);            // 왼쪽 위
//    glEnd();
//}
//
//void Switch_drawFinger(float x, float y, float width, float height) {
//    // 손가락의 본체 (직사각형)
//    glColor3f(1.0f, 0.8f, 0.6f); // 살색
//    glBegin(GL_QUADS);
//    glVertex2f(x, y + Switch_fingerDown);                      // 왼쪽 아래
//    glVertex2f(x + width, y + Switch_fingerDown);              // 오른쪽 아래
//    glVertex2f(x + width, y - height + Switch_fingerDown);     // 오른쪽 위
//    glVertex2f(x, y - height + Switch_fingerDown);             // 왼쪽 위
//    glEnd();
//
//    // 손가락 끝부분 (반원, 아래 방향)
//    Switch_drawSemiCircle(x + width / 2.0f, y - height + Switch_fingerDown, (width / 2.0f));
//
//    // 손톱 추가 (반원 위쪽)
//    float nailWidth = width * 0.6f;   // 손톱 너비 (손가락 너비의 60%)
//    float nailHeight = height * 0.2f; // 손톱 높이 (손가락 길이의 20%)
//    float nailX = x + (width - nailWidth) / 2.0f; // 손톱 시작 X 좌표
//    float nailY = y - height + Switch_fingerDown + nailHeight * 0.2f; // 손톱 시작 Y 좌표
//    Switch_drawNail(nailX, nailY, nailWidth, nailHeight);
//}
//
//
//void Switch_timer(int value) {
//    if (Switch_shrinking) {
//        Switch_heightScale -= 0.1f;
//        if (Switch_heightScale <= -0.1f) {
//            Switch_shrinking = false;
//        }
//    }
//    else {
//        Switch_heightScale += 0.1f;  // 세로 크기 늘리기
//        if (Switch_heightScale >= 0.0f) {
//            Switch_shrinking = true;  // 다시 크기 줄이기 시작
//        }
//    }
//
//    glutPostRedisplay();  // 화면을 다시 그리도록 요청
//
//}
//void finger_timer(int value) {
//    if (Switch_fingerDown > -0.3f) { // 손가락이 내려갈 때
//        Switch_fingerDown -= 0.00135f;  // 손가락을 조금씩 아래로 움직임
//    }
//    else {
//        Switch_fingerDown = -0.3f;   // 더 이상 내려가지 않도록 고정
//    }
//    glutPostRedisplay();      // 화면을 다시 그리도록 요청
//    glutTimerFunc(16, finger_timer, 0); // 16ms 간격으로 반복 호출 (약 60FPS)
//}
//
//void Switch_playSound(const char* soundFile) {
//    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
//}
//
//void Switch_display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//    glLoadIdentity();
//
//    Switch_Bombswitch();
//    Switch_Line();
//    Switch_BombSwitch2();
//    glPushMatrix();
//    glTranslated(0.0f, 1.0f, 0.0f);
//    Switch_drawFinger(-0.2f, 0.5f, 0.4f, 1.2f);
//    glPopMatrix();
//    glEnd();
//    glFlush();
//    glutSwapBuffers();
//}
//
//void Switch_init() {
//    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
//    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene9");
//
//    Switch_init();
//
//    glutDisplayFunc(Switch_display);
//    Switch_playSound("핵.wav");
//    glutTimerFunc(3500, Switch_timer, 0);
//    glutTimerFunc(1, finger_timer, 0);
//    glutMainLoop();
//
//    return 0;
//}