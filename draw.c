#include <raylib.h>
#include <raymath.h>

#define N(argo)                                                                \
  void argo(long b, long *o, long t, void *u, long s, long x, long y,          \
            long *cells)

static Camera2D camera = {0};
static Vector2 panStart = {0};
static Color colors[] = {BLUE, GREEN, YELLOW, RED, PINK};
static Font font;
static int semiAuto = 1;
static int available_time = 46;
static int show_incomplete_theorems = 1;

#include <stdio.h>
void drawTextAt(Rectangle r, int offsetX, int offsetY, int size,
                const char *fmt, ...) {
  char buffer[32];
  va_list args;
  va_start(args, fmt);
  vsnprintf(buffer, sizeof(buffer), fmt, args);
  va_end(args);
  DrawTextEx(font, buffer, (Vector2){r.x + offsetX, r.y + offsetY}, size, 0,
             BLACK);
}

#define CELL_SIZE 32
#define FONT_SIZE_SMALL 10
#define FONT_SIZE_LARGE 20
#define TEXT_OFFSET_X 5
#define TEXT_OFFSET_Y 20
void drawCell(int x, int y, long *o, long t, Color c) {
  Rectangle rect = {x * CELL_SIZE, y * CELL_SIZE, CELL_SIZE, CELL_SIZE};
  if (o[t] == 1)

    DrawRectangle(rect.x, rect.y, 20, rect.height, c),
        DrawTriangle(
            (Vector2){rect.x + rect.width, rect.y + rect.height / 2.0f},
            (Vector2){rect.x + 20, rect.y},
            (Vector2){rect.x + 20, rect.y + rect.height}, c);
  else if (o[t] == 3)
    DrawRectangle(rect.x, rect.y, rect.width, 10, c),
        DrawRectangle(rect.x + 10, rect.y, 10, rect.height, c);
  else if (o[t] == 2)
    DrawRectangleLinesEx(rect, 10, c);
  drawTextAt(rect, TEXT_OFFSET_X, 0, FONT_SIZE_SMALL, "%ld", o[t]);
  drawTextAt(rect, TEXT_OFFSET_X, TEXT_OFFSET_Y, FONT_SIZE_SMALL, "%ld", t);
  drawTextAt(rect, TEXT_OFFSET_X + 7, 5, FONT_SIZE_LARGE, "%c", o[t + 1]);
}
void drawCircle(int x, int y, long *o, long t, Color c) {
  int r = CELL_SIZE / 2;
  DrawCircle(x * CELL_SIZE + r, y * CELL_SIZE + r, r, c);
}

void handleZoom(void) {
  float wheel = GetMouseWheelMove();
  if (wheel != 0) {
    Vector2 mouseWorld = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.zoom = Clamp(camera.zoom + wheel * 0.1f, 0.1f, 10.0f);
    Vector2 newMouseWorld = GetScreenToWorld2D(GetMousePosition(), camera);
    camera.target =
        Vector2Add(camera.target, Vector2Subtract(mouseWorld, newMouseWorld));
  }
}

void handlePan(void) {
  if (IsMouseButtonPressed(MOUSE_RIGHT_BUTTON)) {
    panStart = GetMousePosition();
  } else if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) {
    Vector2 delta = Vector2Scale(Vector2Subtract(panStart, GetMousePosition()),
                                 1.0f / camera.zoom);
    camera.target = Vector2Add(camera.target, delta);
    panStart = GetMousePosition();
  }
}
void handleAvailableTime(void) {
  if (IsMouseButtonDown(MOUSE_LEFT_BUTTON)) {
    Vector2 mouseWorld = GetScreenToWorld2D(GetMousePosition(), camera);
    available_time = mouseWorld.x / CELL_SIZE;
    if (available_time < 3)
      available_time = 3;
  }
}

N(debug_draw) {
  int key;
  if ((o[cells[2]] == 1 && cells[1] == 1) || show_incomplete_theorems)
    do {
      handleZoom();
      handlePan();
      handleAvailableTime();

      BeginDrawing();
      ClearBackground(RAYWHITE);
      BeginMode2D(camera);

      for (long t = 0, x = 0, y = 0; t < s; t += 2, x++)
        drawCell(x, y, o, t, (cells[2] == t) ? colors[cells[3]] : GRAY);
      for (long *c = cells; c; c = (long *)c[4])
        drawCell(c[0], c[1], o, c[2], colors[c[3]]);

      DrawLine(available_time * CELL_SIZE, 0, available_time * CELL_SIZE,
               GetScreenHeight() - camera.offset.y, BLACK);

      EndMode2D();
      DrawTextEx(font,
                 "Press 'n' key for choice, left click to set available time, "
                 "use mouse wheel to zoom, right-drag to pan",
                 (Vector2){10, 10}, FONT_SIZE_LARGE, 0, GRAY);
      if (show_incomplete_theorems)
        DrawTextEx(font, "Press 't' to show compelte theorems.",
                   (Vector2){10, 30}, FONT_SIZE_LARGE, 0, GRAY);
      else
        DrawTextEx(font, "Press 't' to show theorem constuction process.",
                   (Vector2){10, 30}, FONT_SIZE_LARGE, 0, GRAY);
      EndDrawing();

      key = GetCharPressed();
      if (key == 's')
        semiAuto = !semiAuto;
      else if (key == 't')
        show_incomplete_theorems = !show_incomplete_theorems;
      if (WindowShouldClose())
        return;
    } while (key != 'n' && semiAuto);
  if (x < available_time)
    ((N((*)))o[s])(b, o, t, u, s, x, y, cells);
}

void debug_close(void) { CloseWindow(); }

void debug_init(void) {
  SetTraceLogLevel(LOG_ERROR);
  SetTargetFPS(60);
  InitWindow(0, 0, "The choice machine");
  font = LoadFontEx("NovaMono-Regular.ttf", 60, 0, 0);
  camera.offset = (Vector2){CELL_SIZE, 3 * CELL_SIZE};
  camera.zoom = 1.0f;
  camera.rotation = 0;
  camera.target = (Vector2){0};
}
