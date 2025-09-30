//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include <GL/glut.h>
//#include <stdio.h>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLuint JW_textureID;  // 텍스처 ID
//int JW_width, JW_height; // 텍스처의 크기
//
//// 텍스처 로딩 함수
//void loadImage(const char* filename) {
//    int channels;
//    unsigned char* image = stbi_load(filename, &JW_width, &JW_height, &channels, 0);
//    if (image) {
//        glGenTextures(1, &JW_textureID);
//        glBindTexture(GL_TEXTURE_2D, JW_textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, JW_width, JW_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        stbi_image_free(image);
//    }
//    else {
//        printf("Failed to load image: %s\n", filename);
//    }
//}
//
//typedef struct {
//    float x, y;
//    float speed;
//    float size;
//} Snowflake;
//
//#define NUM_SNOWFLAKES 100
//Snowflake snowflakes[NUM_SNOWFLAKES];
//
//void initSnowflakes() {
//    for (int i = 0; i < NUM_SNOWFLAKES; i++) {
//        snowflakes[i].x = (rand() % 200) - 100;
//        snowflakes[i].y = (rand() % 200) + 100;
//        snowflakes[i].speed = ((rand() % 5) + 1) / 10.0f;
//        snowflakes[i].size = (rand() % 3) + 1;
//    }
//}
//
//void drawSnowflakes() {
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glPointSize(7.0f);
//
//    glBegin(GL_POINTS);
//    for (int i = 0; i < NUM_SNOWFLAKES; i++) {
//        glVertex2f(snowflakes[i].x, snowflakes[i].y);
//    }
//    glEnd();
//}
//
//void updateSnowflakes() {
//    for (int i = 0; i < NUM_SNOWFLAKES; i++) {
//        snowflakes[i].y -= snowflakes[i].speed;
//        if (snowflakes[i].y < -100) {
//            snowflakes[i].y = 100;
//            snowflakes[i].x = (rand() % 200) - 100;
//        }
//    }
//}
//
//void JW_display() {
//    glClear(GL_COLOR_BUFFER_BIT);
//
//    // 텍스처의 비율을 화면 비율에 맞게 조정
//    float aspectRatio = (float)JW_width / (float)JW_height;  // 이미지 비율
//    float windowAspect = (float)800 / (float)600;  // 화면 비율 (800x600)
//
//    // 화면 비율에 맞게 사각형 크기 조정
//    float drawWidth = 100.0f;
//    float drawHeight = 100.0f;
//
//    if (aspectRatio > windowAspect) {
//        drawHeight = drawWidth / aspectRatio;  // 화면에 맞게 높이를 조정
//    }
//    else {
//        drawWidth = drawHeight * aspectRatio;  // 화면에 맞게 너비를 조정
//    }
//
//    // 배경 이미지 그리기
//    glBindTexture(GL_TEXTURE_2D, JW_textureID);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-drawWidth, -drawHeight);
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(drawWidth, -drawHeight);
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(drawWidth, drawHeight);
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-drawWidth, drawHeight);
//    glEnd();
//
//    // 눈송이 그리기
//    drawSnowflakes();
//
//    glutSwapBuffers();
//}
//void JW_playSound(const char* soundFile) {
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //일반 재생
//}
//
//void JW_idle() {
//    updateSnowflakes();
//    glutPostRedisplay();
//}
//
//void setupOrtho() {
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-100.0, 90.0, -60.0, 60.0);  // 화면 크기에 맞는 범위로 조정
//    glMatrixMode(GL_MODELVIEW);
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene6");
//
//    loadImage("JW.png");  // 이미지 경로를 확인
//    initSnowflakes();
//
//    setupOrtho();  // 2D 좌표계를 설정
//
//    glutDisplayFunc(JW_display);
//    glutIdleFunc(JW_idle);
//    glEnable(GL_TEXTURE_2D);
//    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
//
//    JW_playSound("종우야.wav");
//
//
//    glutMainLoop();
//    return 0;
//}