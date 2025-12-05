#include "terminal_utils.h"
#include "Picture.h"

Picture::Picture(int ls, int rs, int cs, Line *l, Rect *r, Circle *c){
    this->line_size = ls;
    this->rect_size = rs;
    this->circle_size = cs;

    this->line_ptr = l;
    this->rect_ptr = r;
    this->circle_ptr = c;
}

void Picture::setLines(int s, Line *l){
    this->line_size = s;
    this->line_ptr = l;
}

void Picture::setRects(int s, Rect *r){
    this->rect_size = s;
    this->rect_ptr = r;
}

void Picture::setCircles(int s, Circle *c){
    this->circle_size = s;
    this->circle_ptr = c;
}

void Picture::draw(SDL_Renderer* renderer){
    for(int i = 0; i < this->line_size; i++){
        this->line_ptr[i].draw(renderer);
    }
    for(int i = 0; i < this->rect_size; i++){
        this->rect_ptr[i].draw(renderer);
    }
    for(int i = 0; i < this->circle_size; i++){
        this->circle_ptr[i].draw(renderer);
    }
}