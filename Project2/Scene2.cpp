//#define STB_IMAGE_IMPLEMENTATION
//#include <GL/glut.h>
//#include "stb_image.h"
//#include <iostream>
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLuint texture1, texture2, texture3, texture4; // �� �ؽ�ó ID�� ������ ����
//float angle = 0.0f;
//bool rotateDirection = true; // ȸ�� ���� (true: �ð����, false: �ݽð����)
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
//    // �ؽ�ó ���� ����
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    // �ؽ�ó ������ ���ε�
//    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0,
//        channels == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, image);
//
//    stbi_image_free(image); // �޸� ����
//    return texture;
//}
//
//void init2() {
//    glEnable(GL_TEXTURE_2D); // �ؽ�ó Ȱ��ȭ
//    glEnable(GL_BLEND);      // ���� Ȱ��ȭ
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // ���� ���� ����
//
//    // �ؽ�ó �ε�
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
//    // ù ��° �ؽ�ó
//    glBindTexture(GL_TEXTURE_2D, texture1);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, -0.5f); // ���ϴ�
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.6f, -0.5f); // ���ϴ�
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.6f, 0.6f); // ����
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.6f); // �»��
//    glEnd();
//
//    // �� ��° �ؽ�ó
//    glBindTexture(GL_TEXTURE_2D, texture2);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-0.5f, -0.5f);  // ���ϴ�
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(0.6f, -0.5f);  // ���ϴ�
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(0.6f, 0.6f);  // ����
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-0.5f, 0.6f);  // �»��
//    glEnd();
//
//    glBindTexture(GL_TEXTURE_2D, texture3);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.3f, -1.0f);  // ���ϴ�
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.0f, -1.0f);  // ���ϴ�
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.0f, 0.3f);  // ����
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.3f, 0.3f);  // �»��
//    glEnd();
//
//
//    // �� ��° �ؽ�ó (ȸ��)
//    glPushMatrix();
//    glTranslatef(0.0f, -0.4f, 0.0f); // �߽� �̵�
//    glRotatef(angle, 0.0f, 0.0f, 1.0f); // ȸ�� ����
//    glTranslatef(0.0f, 0.4f, 0.0f); // �ٽ� ���� ��ġ�� �̵�
//
//    glBindTexture(GL_TEXTURE_2D, texture4);
//    glBegin(GL_QUADS);
//    glTexCoord2f(0.0f, 1.0f); glVertex2f(-1.5f, -1.0f);  // ���ϴ�
//    glTexCoord2f(1.0f, 1.0f); glVertex2f(1.2f, -1.1f);  // ���ϴ�
//    glTexCoord2f(1.0f, 0.0f); glVertex2f(1.2f, 0.3f);  // ����
//    glTexCoord2f(0.0f, 0.0f); glVertex2f(-1.5f, 0.3f);  // �»��
//    glEnd();
//    glPopMatrix();
//
//    glutSwapBuffers();
//}
//void playSound2(const char* soundFile) {
//    //PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC | SND_LOOP); //���� ���
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
//}
//void timer2(int value) {
//    if (rotateDirection) {
//        angle += 0.7f; // ������ ����
//        if (angle >= 20.0f) rotateDirection = false; // �ð� ���� ���� ���� �� ����
//    }
//    else {
//        angle -= 0.7f; // ������ ����
//        if (angle <= -20.0f) rotateDirection = true; // �ݽð� ���� ���� ���� �� ����
//    }
//
//    glutPostRedisplay(); // ���÷��� ������Ʈ ��û
//    glutTimerFunc(16, timer2, 0); // 16ms �� Ÿ�̸� ��ȣ�� 
//}
//
//void initScene2(){
//    init2();
//    playSound2("����.wav");
//
//    glutDisplayFunc(display2);
//    glutTimerFunc(0, timer2, 0); // Ÿ�̸� ����
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene2");
//
//    init2();
//    playSound2("����.wav");
//
//    glutDisplayFunc(display2);
//    glutTimerFunc(0, timer2, 0); // Ÿ�̸� ����
//    glutMainLoop();
//    return 0;
//}