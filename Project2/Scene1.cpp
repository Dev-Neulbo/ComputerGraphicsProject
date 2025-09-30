#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>  // cos, sin �Լ� ����� ���� ��� ���� �߰�
#include <Windows.h> 
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")       

// ī�޶� ȸ�� ����
float Table_cameraAngle = 0.0f;
float Table_cameraStartTime = 0.0f;
float Table_cameraDuration = 3000.0f;  // 3�� (3000ms)

// å�� ����
void Table_drawDesk() {
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // å�� ��ġ ����

    // �β� �߰� 
    glColor3f(0.2f, 0.1f, 0.05f);
    glBegin(GL_QUADS);
    glVertex3f(-5.0f, -0.9f, -2.0f);  // ���� ��
    glVertex3f(5.0f, -0.9f, -2.0f);   // ������ ��
    glVertex3f(5.0f, -0.9f, 2.0f);    // ������ ��
    glVertex3f(-5.0f, -0.9f, 2.0f);   // ���� ��
    glEnd();

    // å�� �ٸ�
    glColor3f(0.2f, 0.1f, 0.05f);


    // ���� �� �ٸ�
    glPushMatrix();
    glTranslatef(-4.0f, -2.0f, -1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // ������ �� �ٸ�
    glPushMatrix();
    glTranslatef(4.0f, -2.0f, -1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // ���� �� �ٸ�
    glPushMatrix();
    glTranslatef(-4.0f, -2.0f, 1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // ������ �� �ٸ�
    glPushMatrix();
    glTranslatef(4.0f, -2.0f, 1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}

// 
void Table_drawRoom() {
    // �ٴ�
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);  	 // ���� �Ʒ�
    glVertex3f(15.0f, -4.0f, -10.0f);  	// ������ �Ʒ�
    glVertex3f(15.0f, -4.0f, 10.0f);    	 // ������ ��
    glVertex3f(-15.0f, -4.0f, 10.0f);   	// ���� ��
    glEnd();

    // �� �� 
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);  // ���� �Ʒ�
    glVertex3f(15.0f, -4.0f, -10.0f);   // ������ �Ʒ�
    glVertex3f(15.0f, 10.0f, -10.0f);    // ������ ��
    glVertex3f(-15.0f, 10.0f, -10.0f);   // ���� ��
    glEnd();

    // ���� �� 
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);   // ���� �Ʒ�
    glVertex3f(-15.0f, -4.0f, 10.0f);   // ������ �Ʒ�
    glVertex3f(-15.0f, 10.0f, 10.0f);    // ������ ��
    glVertex3f(-15.0f, 10.0f, -10.0f);  // ���� ��
    glEnd();

    // ������ ��
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(15.0f, -4.0f, -10.0f);   // ���� �Ʒ�
    glVertex3f(15.0f, -4.0f, 10.0f);   // ������ �Ʒ�
    glVertex3f(15.0f, 10.0f, 10.0f);    // ������ ��
    glVertex3f(15.0f, 10.0f, -10.0f);  // ���� ��
    glEnd();

    // �� ��
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, 10.0f);  // ���� �Ʒ�
    glVertex3f(15.0f, -4.0f, 10.0f);   // ������ �Ʒ�
    glVertex3f(15.0f, 10.0f, 10.0f);   // ������ ��
    glVertex3f(-15.0f, 10.0f, 10.0f);  // ���� ��
    glEnd();
}

// ����
void Table_drawChair() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-1.0f, -3.0f, -3.0f);
    glVertex3f(-0.0f, -4.0f, -4.0f);
    glVertex3f(-4.0f, -5.0f, -5.0f);
    glEnd();
}

// ī�޶� ������Ʈ
void Table_updateCamera(int value) {
    if (Table_cameraStartTime == 0.0f) {
        Table_cameraStartTime = glutGet(GLUT_ELAPSED_TIME);
    }

    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) - Table_cameraStartTime;  // ��� �ð� ���

    if (elapsedTime < Table_cameraDuration) {
        Table_cameraAngle += 0.0001f;  // ī�޶� ���� ����
    }

    // ī�޶� ��ġ�� ���������� ȸ��
    float eyeX = 10.0f * cos(Table_cameraAngle);  // ī�޶� X 
    float eyeZ = 10.0f * sin(Table_cameraAngle);  // ī�޶� Z 

    // ī�޶� ��ġ ����
    gluLookAt(eyeX, 2.5f, eyeZ,
        0.0f, 0.0f, 0.0f,   // ����
        0.0f, 1.0f, 0.0f);

    if (elapsedTime < Table_cameraDuration) {
        glutTimerFunc(16, Table_updateCamera, 0);  // ī�޶� ������Ʈ
    }
}

void Table_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // ī�޶� ������Ʈ
    Table_updateCamera(0);

    // ��
    Table_drawRoom();

    // å��
    Table_drawDesk();

    // ����
    Table_drawChair();

    glutSwapBuffers();
}

void Table_init() {
    glEnable(GL_DEPTH_TEST);  // ���� �׽�Ʈ Ȱ��ȭ


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.333f, 1.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Table_playSound(const char* soundFile) {
    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Room with Desk");
    Table_playSound("����.wav");
    Table_init();
    glutDisplayFunc(Table_display);
    glutIdleFunc(Table_display);
    glutMainLoop();
    return 0;
}