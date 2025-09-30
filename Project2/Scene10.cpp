//#include <GL/glut.h>
//#include <GL/glu.h>
//#include <cmath>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//
//float Switch_heightScale = 0.0f;  // �ʱ� ���̸� 1�� ����
//float Switch_fingerDown = 0.0f;
//bool Switch_shrinking = true;     // ũ�Ⱑ �پ��� �ִ��� ����
//float Switch_M_PI = 3.14;
//
//void Switch_Bombswitch() {
//
//    glColor3f(0.5f, 0.5f, 0.5f);  // ö��
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
//    glColor3f(1.0f, 0.0f, 0.0f);  // ������
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
//    glVertex2f(centerX, centerY); // �߽���
//    for (int angle = 180; angle <= 360; ++angle) { // 180�� ~ 360��
//        float rad = angle * Switch_M_PI / 180.0f; // ������ �������� ��ȯ
//        float x = centerX + radius * cos(rad);
//        float y = centerY + radius * sin(rad);
//        glVertex2f(x, y);
//    }
//    glEnd();
//}
//void Switch_drawNail(float x, float y, float width, float height) {
//    glColor3f(1.0f, 0.9f, 0.9f); // ���� ���
//    glBegin(GL_QUADS);
//    glVertex2f(x, y);                     // ���� �Ʒ�
//    glVertex2f(x + width, y);             // ������ �Ʒ�
//    glVertex2f(x + width, y + height);    // ������ ��
//    glVertex2f(x, y + height);            // ���� ��
//    glEnd();
//}
//
//void Switch_drawFinger(float x, float y, float width, float height) {
//    // �հ����� ��ü (���簢��)
//    glColor3f(1.0f, 0.8f, 0.6f); // ���
//    glBegin(GL_QUADS);
//    glVertex2f(x, y + Switch_fingerDown);                      // ���� �Ʒ�
//    glVertex2f(x + width, y + Switch_fingerDown);              // ������ �Ʒ�
//    glVertex2f(x + width, y - height + Switch_fingerDown);     // ������ ��
//    glVertex2f(x, y - height + Switch_fingerDown);             // ���� ��
//    glEnd();
//
//    // �հ��� ���κ� (�ݿ�, �Ʒ� ����)
//    Switch_drawSemiCircle(x + width / 2.0f, y - height + Switch_fingerDown, (width / 2.0f));
//
//    // ���� �߰� (�ݿ� ����)
//    float nailWidth = width * 0.6f;   // ���� �ʺ� (�հ��� �ʺ��� 60%)
//    float nailHeight = height * 0.2f; // ���� ���� (�հ��� ������ 20%)
//    float nailX = x + (width - nailWidth) / 2.0f; // ���� ���� X ��ǥ
//    float nailY = y - height + Switch_fingerDown + nailHeight * 0.2f; // ���� ���� Y ��ǥ
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
//        Switch_heightScale += 0.1f;  // ���� ũ�� �ø���
//        if (Switch_heightScale >= 0.0f) {
//            Switch_shrinking = true;  // �ٽ� ũ�� ���̱� ����
//        }
//    }
//
//    glutPostRedisplay();  // ȭ���� �ٽ� �׸����� ��û
//
//}
//void finger_timer(int value) {
//    if (Switch_fingerDown > -0.3f) { // �հ����� ������ ��
//        Switch_fingerDown -= 0.00135f;  // �հ����� ���ݾ� �Ʒ��� ������
//    }
//    else {
//        Switch_fingerDown = -0.3f;   // �� �̻� �������� �ʵ��� ����
//    }
//    glutPostRedisplay();      // ȭ���� �ٽ� �׸����� ��û
//    glutTimerFunc(16, finger_timer, 0); // 16ms �������� �ݺ� ȣ�� (�� 60FPS)
//}
//
//void Switch_playSound(const char* soundFile) {
//    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
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
//    Switch_playSound("��.wav");
//    glutTimerFunc(3500, Switch_timer, 0);
//    glutTimerFunc(1, finger_timer, 0);
//    glutMainLoop();
//
//    return 0;
//}