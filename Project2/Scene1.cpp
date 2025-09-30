#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>  // cos, sin 함수 사용을 위한 헤더 파일 추가
#include <Windows.h> 
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")       

// 카메라 회전 각도
float Table_cameraAngle = 0.0f;
float Table_cameraStartTime = 0.0f;
float Table_cameraDuration = 3000.0f;  // 3초 (3000ms)

// 책상 설정
void Table_drawDesk() {
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.0f);  // 책상 위치 조정

    // 두께 추가 
    glColor3f(0.2f, 0.1f, 0.05f);
    glBegin(GL_QUADS);
    glVertex3f(-5.0f, -0.9f, -2.0f);  // 왼쪽 앞
    glVertex3f(5.0f, -0.9f, -2.0f);   // 오른쪽 앞
    glVertex3f(5.0f, -0.9f, 2.0f);    // 오른쪽 뒤
    glVertex3f(-5.0f, -0.9f, 2.0f);   // 왼쪽 뒤
    glEnd();

    // 책상 다리
    glColor3f(0.2f, 0.1f, 0.05f);


    // 왼쪽 앞 다리
    glPushMatrix();
    glTranslatef(-4.0f, -2.0f, -1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // 오른쪽 앞 다리
    glPushMatrix();
    glTranslatef(4.0f, -2.0f, -1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // 왼쪽 뒤 다리
    glPushMatrix();
    glTranslatef(-4.0f, -2.0f, 1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    // 오른쪽 뒤 다리
    glPushMatrix();
    glTranslatef(4.0f, -2.0f, 1.5f);
    glScalef(0.2f, 2.0f, 0.2f);
    glutSolidCube(1.0f);
    glPopMatrix();

    glPopMatrix();
}

// 
void Table_drawRoom() {
    // 바닥
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);  	 // 왼쪽 아래
    glVertex3f(15.0f, -4.0f, -10.0f);  	// 오른쪽 아래
    glVertex3f(15.0f, -4.0f, 10.0f);    	 // 오른쪽 위
    glVertex3f(-15.0f, -4.0f, 10.0f);   	// 왼쪽 위
    glEnd();

    // 뒷 벽 
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);  // 왼쪽 아래
    glVertex3f(15.0f, -4.0f, -10.0f);   // 오른쪽 아래
    glVertex3f(15.0f, 10.0f, -10.0f);    // 오른쪽 위
    glVertex3f(-15.0f, 10.0f, -10.0f);   // 왼쪽 위
    glEnd();

    // 왼쪽 벽 
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, -10.0f);   // 왼쪽 아래
    glVertex3f(-15.0f, -4.0f, 10.0f);   // 오른쪽 아래
    glVertex3f(-15.0f, 10.0f, 10.0f);    // 오른쪽 위
    glVertex3f(-15.0f, 10.0f, -10.0f);  // 왼쪽 위
    glEnd();

    // 오른쪽 벽
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(15.0f, -4.0f, -10.0f);   // 왼쪽 아래
    glVertex3f(15.0f, -4.0f, 10.0f);   // 오른쪽 아래
    glVertex3f(15.0f, 10.0f, 10.0f);    // 오른쪽 위
    glVertex3f(15.0f, 10.0f, -10.0f);  // 왼쪽 위
    glEnd();

    // 앞 벽
    glColor3f(0.2f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -4.0f, 10.0f);  // 왼쪽 아래
    glVertex3f(15.0f, -4.0f, 10.0f);   // 오른쪽 아래
    glVertex3f(15.0f, 10.0f, 10.0f);   // 오른쪽 위
    glVertex3f(-15.0f, 10.0f, 10.0f);  // 왼쪽 위
    glEnd();
}

// 의자
void Table_drawChair() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-2.0f, -2.0f, -2.0f);
    glVertex3f(-1.0f, -3.0f, -3.0f);
    glVertex3f(-0.0f, -4.0f, -4.0f);
    glVertex3f(-4.0f, -5.0f, -5.0f);
    glEnd();
}

// 카메라 업데이트
void Table_updateCamera(int value) {
    if (Table_cameraStartTime == 0.0f) {
        Table_cameraStartTime = glutGet(GLUT_ELAPSED_TIME);
    }

    float elapsedTime = glutGet(GLUT_ELAPSED_TIME) - Table_cameraStartTime;  // 경과 시간 계산

    if (elapsedTime < Table_cameraDuration) {
        Table_cameraAngle += 0.0001f;  // 카메라 각도 증가
    }

    // 카메라 위치를 오른쪽으로 회전
    float eyeX = 10.0f * cos(Table_cameraAngle);  // 카메라 X 
    float eyeZ = 10.0f * sin(Table_cameraAngle);  // 카메라 Z 

    // 카메라 위치 설정
    gluLookAt(eyeX, 2.5f, eyeZ,
        0.0f, 0.0f, 0.0f,   // 원점
        0.0f, 1.0f, 0.0f);

    if (elapsedTime < Table_cameraDuration) {
        glutTimerFunc(16, Table_updateCamera, 0);  // 카메라 업데이트
    }
}

void Table_display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // 카메라 업데이트
    Table_updateCamera(0);

    // 벽
    Table_drawRoom();

    // 책상
    Table_drawDesk();

    // 의자
    Table_drawChair();

    glutSwapBuffers();
}

void Table_init() {
    glEnable(GL_DEPTH_TEST);  // 깊이 테스트 활성화


    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.333f, 1.0f, 50.0f);
    glMatrixMode(GL_MODELVIEW);
}
void Table_playSound(const char* soundFile) {
    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Room with Desk");
    Table_playSound("긴장.wav");
    Table_init();
    glutDisplayFunc(Table_display);
    glutIdleFunc(Table_display);
    glutMainLoop();
    return 0;
}