//#include <iostream>
//#include <GL/glut.h>
//#define STB_IMAGE_IMPLEMENTATION
//#include "stb_image.h"
//#include <Windows.h> 
//#include <mmsystem.h>
//#pragma comment(lib,"winmm.lib")    
//
//GLint F35_width, F35_height;
//float F35_xOffset = 0.0f;     // X�� �̵����� �����ϴ� ����
//float F35_yOffset = 0.0f;
//
//
//// �ؽ�ó ID ����
//GLuint F35_texID;
//
//// �ؽ�ó�� ���Ͽ��� �ε��ϴ� �Լ�
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
//// �ʱ�ȭ �Լ�
//void F35_init() {
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_BLEND);
//    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//
//    // �ؽ�ó �ε�
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
//    stbi_image_free(bitmap);  // �޸� ����
//}
//
//void F35_drawMissile() {
//    // �̻��� �պκ�
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.6f, 0.3f, 0.0f); // ����
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//    glEnd();
//
//    // �̻��� ����
//    glBegin(GL_TRIANGLES);
//    glColor3f(0.5f, 0.5f, 0.5f); // ȸ��
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
//    // �̻��� ����
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
//    // �̻��� �պκ�
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//
//    glVertex3f(-0.5, 0.0, 0.0);
//    glVertex3f(-0.25, -0.1, 0.0);
//
//    glVertex3f(-0.25, -0.1, 0.0);
//    glVertex3f(-0.3, 0.15, 0.0);
//
//    // �̻��� ����
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
//    // �̻��� ����
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
//    // �Ҳ�
//    glBegin(GL_TRIANGLES);
//
//    glPushMatrix();
//    glColor3f(1.0f, 0.5f, 0.0f); // ��Ȳ��
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
//    glColor3f(1.0f, 0.0f, 0.0f); // ������
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
//    glColor3f(1.0f, 0.2f, 0.0f); // �� ������
//    glVertex3f(0.36, 0.015, 0.0);
//    glVertex3f(0.33, 0.225, 0.0);
//    glVertex3f(0.46, 0.1, 0.0);
//    glPopMatrix();
//
//    glPushMatrix();
//    glColor3f(1.0f, 1.0f, 1.0f); // �Ͼ��
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
//// �簢�� �׸���
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
//    F35_xOffset -= 0.05f;           // X�� �������� �̵� (�ӵ� ����)
//    F35_yOffset -= 0.05f;
//    if (F35_xOffset < -2.5f || F35_yOffset < -2.5f) {      // �̻����� ȭ���� ����� �ʱ�ȭ
//        F35_xOffset = 0.0f;
//        F35_yOffset = 0.0f;
//    }
//    glutPostRedisplay();        // ȭ���� �ٽ� �׸�
//    glutTimerFunc(30, F35_toggleFire, 0); // 50ms���� ȣ��
//}
//void F35_drawBackground() {
//    glDisable(GL_DEPTH_TEST);  // ���� �׽�Ʈ ��Ȱ��ȭ
//    glEnable(GL_TEXTURE_2D);
//    glBindTexture(GL_TEXTURE_2D, F35_texID);
//
//    F35_drawBox_1();
//    F35_drawBox_2();
//
//    glDisable(GL_TEXTURE_2D);
//    glEnable(GL_DEPTH_TEST);   // ���� �׽�Ʈ �ٽ� Ȱ��ȭ
//}
//
//// ������ �׸��� �Լ� ����
//void F35_drawClouds() {
//    glPushMatrix();
//    glColor4f(1.0f, 1.0f, 1.0f, 0.5f);  // �Ͼ��, �ణ ������ ���� ����
//
//    // ���� ��ġ ���� (���� ��ġ�� ���� ��ġ)
//    float cloudPositions[10][2] = {
//        {-1.4f, -0.8f}, {-1.2f, 1.3f}, {-0.3f, -0.75f}, {1.0f, -0.85f}, {0.3f, -1.4f},
//        {-0.7f, 1.6f}, {1.8f, -0.45f}, {0.5f, -0.3f}, {-0.8f, -1.2f}, {1.2f, -0.1f}
//    };
//
//    // �� ���� ��ġ�� ���� �׸���
//    for (int i = 0; i < 10; ++i) {
//        float x = cloudPositions[i][0];  // ������ X ��ǥ
//        float y = cloudPositions[i][1];  // ������ Y ��ǥ
//
//        glPushMatrix();
//        glTranslatef(x, y, 0.0f);  // ���� ��ġ ����
//        glBegin(GL_POLYGON);
//        for (int j = 0; j < 360; j++) {
//            float angle = j * 3.14159f / 180.0f;
//            float dx = cos(angle) * 0.3f;  // ������ 0.3
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
//    PlaySound(soundFile, 0, SND_FILENAME | SND_ASYNC); //�Ϲ� ���
//}
//
//void F35_Miissile_wav(int value) {
//    F35_playSound("�̻���.wav");
//
//    if (value < 4) {  // 4���� �ݺ�
//        glutTimerFunc(1500, F35_Miissile_wav, value + 1);  // value�� �������Ѽ� �ݺ� Ƚ���� ����
//    }
//}
//
//// ���÷��� �ݹ� �Լ�
//void F35_display() {
//    glClearColor(0.33f, 0.61f, 0.78f, 1.0f);  // �� ��ο� �ϴû����� ��� ���� (RGB ��)
//
//
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//
//
//    glPushMatrix();
//
//    // �̻��� �̵� (X��)
//    glTranslatef(F35_xOffset, F35_yOffset, 0.0f);
//
//    // �̻��� ȸ�� (��: Y�� ���� 45�� ȸ��)
//    glRotatef(40.0f, 0.0f, 0.0f, 1.0f); // ȸ�� ������ �� ����
//
//    // �̻��� �׸���
//    F35_drawMissile();
//
//    // �̻��� ������
//    F35_LINE();
//
//    // �̻��� �Ҳ�
//    F35_fire();
//
//    glPopMatrix();
//    // ��� �׸���
//
//    F35_drawBackground();
//    F35_drawClouds();  // ���� �׸��� 
//
//    glutSwapBuffers();  // ���� ���� ��ü
//}
//
//// ������ ũ�� ���� �ݹ� �Լ�
//void F35_reshape(int w, int h) {
//    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluOrtho2D(-2.0, 2.0, -2.0, 1.0);
//    glMatrixMode(GL_MODELVIEW);
//}
//
//// ���� �Լ�
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Scene4");
//
//    F35_init();
//    glutTimerFunc(500, F35_toggleFire, 0);
//    glutDisplayFunc(F35_display);  // ���÷��� �ݹ� ���
//    glutReshapeFunc(F35_reshape);  // ������ ũ�� ���� �ݹ� ���
//    glutTimerFunc(400, F35_Miissile_wav, 0);
//    glutMainLoop();            // ���� ���� ����
//
//    return 0;
//}