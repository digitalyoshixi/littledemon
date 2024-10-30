#include <gtk/gtk.h>
#include <stdio.h>


static void activate(GtkApplication *app, gpointer user_data) {
    GtkWidget *window;
    GtkWidget *picture;

    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Image Display");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Image display code will go here

    picture = gtk_picture_new_for_filename("demon.png");
    gtk_picture_set_content_fit(GTK_PICTURE(picture), TRUE);
    gtk_widget_set_size_request(picture, 300, 200);
    gtk_window_set_child(GTK_WINDOW(window), picture);

    gtk_window_present(GTK_WINDOW(window));
}
int main(int argc, char **argv) {
  

//  system("echo hello");
//  if (remove("hi.txt")){
//    printf("OK OK\n");
//  }
//  else {
//    return 1;
//  }

  GtkApplication *app;
  int status;

  app = gtk_application_new("org.example.image", G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
  status = g_application_run(G_APPLICATION(app), argc, argv);
  g_object_unref(app);
  
  return status;
}




