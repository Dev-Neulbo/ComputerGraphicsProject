//#define STB_IMAGE_IMPLEMENTATION
//#include <GL/glut.h>
//#include "stb_image.h"
//#include <iostream>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLuint texture1, texture2, texture3, texture4; // 두 텍스처 ID를 저장할 변수
//float angle = 0.0f;
//bool rotateDirection = true; // 회전 방향 (true: 시계방향, false: 반시계방향)
//
//GLuint loadTexture2(const char* filename) {
//    int width, height, channels;
//    unsigned char* image = stbi_load(filename, &width, &height, &channels, 0);
//    if (!image) {
//        std::cerr << "Failed to load image: " << filename << std::endl;
//        exit(1);
//    }
//
//    GLuint texture;
//    glGenTextures(1, &texture);
//    glBindTexture(GL_TEXTURE_2D, texture);
//
//    // 텍스처 매핑 설정
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // 텍스처 데이터 업로드
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
//        channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
//
//    stbi_image_free(image); // 메모리 해제
//    return texture;
//}
//
//void init2() {
//    glEnable(GL_TEXTURE_2D); // 텍스처 활성화
//    glEnable(GL_BLEND);      // 블렌딩 활성화
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // 알파 블렌딩 설정
//
//    // 텍스처 로드
//    texture1 = loadTexture2("JE_Head.png");
//    texture2 = loadTexture2("JE_Body.png");
//    texture3 = loadTexture2("JE_Arm.png");
//    texture4 = loadTexture2("JE_Hand.png");
//}
//
//
//void display2() {
//    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT);
//
//
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    // 첫 번째 텍스처
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, -0.5f); // 좌하단
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.6f, -0.5f); // 우하단
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.6f, 0.6f); // 우상단
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.6f); // 좌상단
//    glEnd();
//
//    // 두 번째 텍스처
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, -0.5f);  // 좌하단
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.6f, -0.5f);  // 우하단
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.6f, 0.6f);  // 우상단
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.6f);  // 좌상단
//    glEnd();
//
//    glBindTexture(GL_TEXTURE_2D, texture3);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.3f, -1.0f);  // 좌하단
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, -1.0f);  // 우하단
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.3f);  // 우상단
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.3f, 0.3f);  // 좌상단
//    glEnd();
//
//
//    // 네 번째 텍스처 (회전)
//    glPushMatrix();
//    glTranslatef(0.0f, -0.4f, 0.0f); // 중심 이동
//    glRotatef(angle, 0.0f, 0.0f, 1.0f); // 회전 적용
//    glTranslatef(0.0f, 0.4f, 0.0f); // 다시 원래 위치로 이동
//
//    glBindTexture(GL_TEXTURE_2D, texture4);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.5f, -1.0f);  // 좌하단
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.2f, -1.1f);  // 우하단
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.2f, 0.3f);  // 우상단
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.5f, 0.3f);  // 좌상단
//    glEnd();
//    glPopMatrix();
//
//    glutSwapBuffers();
//}
//void playSound2(const char* soundFile) {
//    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //루프 재생
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
//}
//void timer2(int value) {
//    if (rotateDirection) {
//        angle += 0.7f; // 각도를 증가
//        if (angle >= 20.0f) rotateDirection = false; // 시계 방향 끝에 도달 시 반전
//    }
//    else {
//        angle -= 0.7f; // 각도를 감소
//        if (angle <= -20.0f) rotateDirection = true; // 반시계 방향 끝에 도달 시 반전
//    }
//
//    glutPostRedisplay(); // 디스플레이 업데이트 요청
//    glutTimerFunc(16, timer2, 0); // 16ms 후 타이머 재호출 
//}
//
//void initScene2(){
//    init2();
//    playSound2("정은.wav");
//
//    glutDisplayFunc(display2);
//    glutTimerFunc(0, timer2, 0); // 타이머 시작
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene2");
//
//    init2();
//    playSound2("정은.wav");
//
//    glutDisplayFunc(display2);
//    glutTimerFunc(0, timer2, 0); // 타이머 시작
//    glutMainLoop();
//    return 0;
//}