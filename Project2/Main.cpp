//#include <iostream>
//#include <GL/glut.h>
//#include "Scenes.h"
//#include <thread>
//#include <chrono>
//
//void display() {
//    if (currentScene == 1) {
//        initScene8(); // Scene3 �׸���
//    }
//    else if (currentScene == 2) {
//        initScene3(); // Scene8 �׸���
//    }
//}
//
//void switchScene(int value) {
//    ++currentScene;
//    glutPostRedisplay(); // ȭ�� ���� ��û
//    glutTimerFunc(10000, switchScene, 0); // 10�� �Ŀ� �ٽ� ȣ��
//}
//
//int main(int argc, char** argv) {
//    glutInit(&argc, argv);
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//    glutInitWindowSize(800, 600);
//    glutCreateWindow("Multi Scene Example");
//
//    glutDisplayFunc(display);
//    glutTimerFunc(10000, switchScene, 0);
//
//    glutMainLoop();
//    return 0;
//}