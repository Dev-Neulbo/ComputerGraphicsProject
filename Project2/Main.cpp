//#include <iostream>
//#include <GL/glut.h>
//#include "Scenes.h"
//#include <thread>
//#include <chrono>
//
//void display() {
//    if (currentScene == 1) {
//        initScene8(); // Scene3 그리기
//    }
//    else if (currentScene == 2) {
//        initScene3(); // Scene8 그리기
//    }
//}
//
//void switchScene(int value) {
//    ++currentScene;
//    glutPostRedisplay(); // 화면 갱신 요청
//    glutTimerFunc(10000, switchScene, 0); // 10초 후에 다시 호출
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