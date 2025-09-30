//#include <iostream>
//#include <GL/glut.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLint F35_width, F35_height;
//float F35_xOffset = 0.0f;     // X축 이동량을 저장하는 변수
//float F35_yOffset = 0.0f;
//
//
//// 텍스처 ID 저장
//GLuint F35_texID;
//
//// 텍스처를 파일에서 로드하는 함수
//unsigned char* F35_LoadMeshFromFile(const char* texFile) {
//    FILE* fp = nullptr;
//    if (fopen_s(&fp, texFile, "rb")) {
//        printf("ERROR : No %s. \n", texFile);
//        return nullptr;
//    }
//
//    int channel;
//    unsigned char* image = stbi_load_from_file(fp, &F35_width, &F35_height, &channel, 0);
//
//    fclose(fp);
//
//    if (!image) {
//        printf("Failed to load texture: %s\n", texFile);
//        return nullptr;
//    }
//
//    return image;
//}
//
//// 초기화 함수
//void F35_init() {
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    // 텍스처 로드
//    unsigned char* bitmap = F35_LoadMeshFromFile("F35.png");
//    if (!bitmap) {
//        exit(EXIT_FAILURE);
//    }
//
//    glGenTextures(1, &F35_texID);
//    glBindTexture(GL_TEXTURE_2D, F35_texID);
//
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, F35_width, F35_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bitmap);
//
//
//    stbi_image_free(bitmap);  // 메모리 해제
//}
//
//void F35_drawMissile() {
//    // 미사일 앞부분
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.6f, 0.3f, 0.0f); // 갈색
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//    glEnd();
//
//    // 미사일 몸통
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.5f, 0.5f, 0.5f); // 회색
//    glVertex3f(-0.3, 0.15, 0.0);
//    glVertex3f(0.15, 0.2, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//
//    glVertex3f(0.15, 0.2, 0.0);
//    glVertex3f(0.2, -0.05, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//
//    glVertex3f(-0.1875, 0.1625, 0.0);
//    glVertex3f(-0.1925, 0.1875, 0.0);
//    glVertex3f(0.0375, 0.1875, 0.0);
//
//    glVertex3f(0.0375, 0.1875, 0.0);
//    glVertex3f(0.0325, 0.2125, 0.0);
//    glVertex3f(-0.1925, 0.1875, 0.0);
//
//    glVertex3f(-0.1375, -0.0875, 0.0);
//    glVertex3f(-0.1325, -0.1125, 0.0);
//    glVertex3f(0.0925, -0.0625, 0.0);
//
//    glVertex3f(0.0925, -0.0625, 0.0);
//    glVertex3f(0.0975, -0.0875, 0.0);
//    glVertex3f(-0.1325, -0.1125, 0.0);
//
//    glVertex3f(-0.1625, 0.0375, 0.0);
//    glVertex3f(0.065, 0.0625, 0.0);
//    glEnd();
//
//    // 미사일 꼬리
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.6f, 0.3f, 0.0f);
//
//    glVertex3f(0.25, 0.175, 0.0);
//    glVertex3f(0.28, 0.025, 0.0);
//    glVertex3f(0.15, 0.2, 0.0);
//
//    glVertex3f(0.15, 0.2, 0.0);
//    glVertex3f(0.2, -0.05, 0.0);
//    glVertex3f(0.28, 0.025, 0.0);
//
//    glEnd();
//}
//
//void F35_LINE() {
//    glLineWidth(2.0f);
//    glColor3f(0.0, 0.0, 0.0);
//    glBegin(GL_LINES);
//    // 미사일 앞부분
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//
//    glVertex3f(-0.25, -0.1, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//
//    // 미사일 몸통
//    glVertex3f(-0.3, 0.15, 0.0);
//    glVertex3f(0.15, 0.2, 0.0);
//
//    glVertex3f(-0.25, -0.1, 0.0);
//    glVertex3f(0.2, -0.05, 0.0);
//
//    glVertex3f(0.15, 0.2, 0.0);
//    glVertex3f(0.2, -0.05, 0.0);
//
//    glVertex3f(-0.1875, 0.1625, 0.0);
//    glVertex3f(-0.1925, 0.1875, 0.0);
//
//    glVertex3f(0.0375, 0.1875, 0.0);
//    glVertex3f(0.0325, 0.2125, 0.0);
//
//    glVertex3f(-0.1925, 0.1875, 0.0);
//    glVertex3f(0.0325, 0.2125, 0.0);
//
//    glVertex3f(-0.1375, -0.0875, 0.0);
//    glVertex3f(-0.1325, -0.1125, 0.0);
//
//    glVertex3f(0.0925, -0.0625, 0.0);
//    glVertex3f(0.0975, -0.0875, 0.0);
//
//    glVertex3f(-0.1325, -0.1125, 0.0);
//    glVertex3f(0.0975, -0.0875, 0.0);
//
//    glVertex3f(-0.1625, 0.0375, 0.0);
//    glVertex3f(0.065, 0.0625, 0.0);
//
//    // 미사일 꼬리
//    glVertex3f(0.25, 0.175, 0.0);
//    glVertex3f(0.28, 0.025, 0.0);
//
//    glVertex3f(0.15, 0.2, 0.0);
//    glVertex3f(0.25, 0.175, 0.0);
//
//    glVertex3f(0.2, -0.05, 0.0);
//    glVertex3f(0.28, 0.025, 0.0);
//    glEnd();
//}
//void F35_fire() {
//
//    // 불꽃
//    glBegin(GL_TRIANGLES);
//
//    glPushMatrix();
//    glColor3f(1.0f, 0.5f, 0.0f); // 주황색
//    glVertex3f(0.25, 0.17, 0.0);
//    glVertex3f(0.33, 0.225, 0.0);
//    glVertex3f(0.28, 0.03, 0.0);
//
//
//    glVertex3f(0.33, 0.225, 0.0);
//    glVertex3f(0.36, 0.015, 0.0);
//    glVertex3f(0.28, 0.03, 0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(1.0f, 0.0f, 0.0f); // 빨간색
//    glVertex3f(0.33, 0.225, 0.0);
//    glVertex3f(0.3, 0.185, 0.0);
//    glVertex3f(0.45, 0.21, 0.0);
//
//    glVertex3f(0.36, 0.15, 0.0);
//    glVertex3f(0.46, 0.1, 0.0);
//    glVertex3f(0.45, 0.21, 0.0);
//
//    glVertex3f(0.325, 0.06, 0.0);
//    glVertex3f(0.36, 0.015, 0.0);
//    glVertex3f(0.46, 0.1, 0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(1.0f, 0.2f, 0.0f); // 더 붉은색
//    glVertex3f(0.36, 0.015, 0.0);
//    glVertex3f(0.33, 0.225, 0.0);
//    glVertex3f(0.46, 0.1, 0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(1.0f, 1.0f, 1.0f); // 하얀색
//    glVertex3f(0.28, 0.03, 0.0);
//    glVertex3f(0.36, 0.015, 0.0);
//    glVertex3f(0.325, 0.06, 0.0);
//    glPopMatrix();
//
//
//    glEnd();
//}
//
//
//// 사각형 그리기
//void F35_drawBox_1() {
//    glBegin(GL_QUADS);
//    glTexCoord2d(0.0, 1.0); glVertex3d(-1.0, -1.0, 0.0);
//    glTexCoord2d(0.0, 0.0); glVertex3d(-1.0, 1.0, 0.0);
//    glTexCoord2d(1.0, 0.0); glVertex3d(1.0, 1.0, 0.0);
//    glTexCoord2d(1.0, 1.0); glVertex3d(1.0, -1.0, 0.0);
//    glEnd();
//}
//void F35_drawBox_2() {
//    glBegin(GL_QUADS);
//    glTexCoord2d(0.0, 1.0); glVertex3d(1.0, -1.3, 0.0);
//    glTexCoord2d(0.0, 0.0); glVertex3d(1.0, -0.7, 0.0);
//    glTexCoord2d(1.0, 0.0); glVertex3d(1.8, -0.7, 0.0);
//    glTexCoord2d(1.0, 1.0); glVertex3d(1.8, -1.3, 0.0);
//    glEnd();
//}
//void F35_toggleFire(int value) {
//
//    F35_xOffset -= 0.05f;           // X축 왼쪽으로 이동 (속도 조정)
//    F35_yOffset -= 0.05f;
//    if (F35_xOffset < -2.5f || F35_yOffset < -2.5f) {      // 미사일이 화면을 벗어나면 초기화
//        F35_xOffset = 0.0f;
//        F35_yOffset = 0.0f;
//    }
//    glutPostRedisplay();        // 화면을 다시 그림
//    glutTimerFunc(30, F35_toggleFire, 0); // 50ms마다 호출
//}
//void F35_drawBackground() {
//    glDisable(GL_DEPTH_TEST);  // 깊이 테스트 비활성화
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, F35_texID);
//
//    F35_drawBox_1();
//    F35_drawBox_2();
//
//    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_DEPTH_TEST);   // 깊이 테스트 다시 활성화
//}
//
//// 구름을 그리는 함수 예시
//void F35_drawClouds() {
//    glPushMatrix();
//    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);  // 하얀색, 약간 투명한 구름 색상
//
//    // 구름 위치 지정 (여러 위치에 구름 배치)
//    float cloudPositions[10][2] = {
//        {-1.4f, -0.8f}, {-1.2f, 1.3f}, {-0.3f, -0.75f}, {1.0f, -0.85f}, {0.3f, -1.4f},
//        {-0.7f, 1.6f}, {1.8f, -0.45f}, {0.5f, -0.3f}, {-0.8f, -1.2f}, {1.2f, -0.1f}
//    };
//
//    // 각 구름 위치에 대해 그리기
//    for (int i = 0; i < 10; ++i) {
//        float x = cloudPositions[i][0];  // 구름의 X 좌표
//        float y = cloudPositions[i][1];  // 구름의 Y 좌표
//
//        glPushMatrix();
//        glTranslatef(x, y, 0.0f);  // 구름 위치 조정
//        glBegin(GL_POLYGON);
//        for (int j = 0; j < 360; j++) {
//            float angle = j * 3.14159f / 180.0f;
//            float dx = cos(angle) * 0.3f;  // 반지름 0.3
//            float dy = sin(angle) * 0.15f;
//            glVertex3f(dx, dy, 0.0f);
//        }
//        glEnd();
//        glPopMatrix();
//    }
//
//    glPopMatrix();
//}
//void F35_playSound(const char* soundFile) {
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
//}
//
//void F35_Miissile_wav(int value) {
//    F35_playSound("미사일.wav");
//
//    if (value < 4) {  // 4번만 반복
//        glutTimerFunc(1500, F35_Miissile_wav, value + 1);  // value를 증가시켜서 반복 횟수를 추적
//    }
//}
//
//// 디스플레이 콜백 함수
//void F35_display() {
//    glClearColor(0.33f, 0.61f, 0.78f, 1.0f);  // 더 어두운 하늘색으로 배경 설정 (RGB 값)
//
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//
//    glPushMatrix();
//
//    // 미사일 이동 (X축)
//    glTranslatef(F35_xOffset, F35_yOffset, 0.0f);
//
//    // 미사일 회전 (예: Y축 기준 45도 회전)
//    glRotatef(40.0f, 0.0f, 0.0f, 1.0f); // 회전 각도와 축 설정
//
//    // 미사일 그리기
//    F35_drawMissile();
//
//    // 미사일 윤곽선
//    F35_LINE();
//
//    // 미사일 불꽃
//    F35_fire();
//
//    glPopMatrix();
//    // 배경 그리기
//
//    F35_drawBackground();
//    F35_drawClouds();  // 구름 그리기 
//
//    glutSwapBuffers();  // 더블 버퍼 교체
//}
//
//// 윈도우 크기 변경 콜백 함수
//void F35_reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-2.0, 2.0, -2.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// 메인 함수
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene4");
//
//    F35_init();
//    glutTimerFunc(500, F35_toggleFire, 0);
//    glutDisplayFunc(F35_display);  // 디스플레이 콜백 등록
//    glutReshapeFunc(F35_reshape);  // 윈도우 크기 변경 콜백 등록
//    glutTimerFunc(400, F35_Miissile_wav, 0);
//    glutMainLoop();            // 메인 루프 실행
//
//    return 0;
//}