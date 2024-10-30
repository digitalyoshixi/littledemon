#include <gtk/gtk.h>
#include <stdio.h>


static void createfire(){
  GtkWidget *picture = gtk_picture_new_for_filename("fire.png");
  gtk_picture_set_content_fit(GTK_PICTURE(picture), TRUE);
  gtk_widget_set_size_request(picture, 200, 200);
  GdkDisplay *display = gdk_display_get_default();
  GListModel *monitors = gdk_display_get_monitors(display);
  GdkMonitor *monitor = GDK_MONITOR(g_list_model_get_item(monitors, 0));
  GdkRectangle workarea;
  gdk_monitor_get_geometry(monitor, &workarea);

  // Generate random coordinates within monitor bounds
  int x = g_random_int_range(0, workarea.width - 200);  // 200 is picture width
  int y = g_random_int_range(0, workarea.height - 200); // 200 is picture height

  // Create a new window for the picture
  GtkWidget *popup = gtk_window_new();
  gtk_window_set_decorated(GTK_WINDOW(popup), FALSE);
  gtk_window_set_default_size(GTK_WINDOW(popup), 200, 200);
  gtk_widget_set_layout_manager(popup, gtk_fixed_layout_new());
  gtk_fixed_move(GTK_FIXED(popup), picture, x, y);
  gtk_window_set_child(GTK_WINDOW(popup), picture);
  gtk_window_present(GTK_WINDOW(popup));
}

static void createdemon(GtkApplication *app){
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Little Demon");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 300);


    // Image 
    GtkWidget *picture = gtk_picture_new_for_filename("demon.png");
    gtk_picture_set_content_fit(GTK_PICTURE(picture), TRUE);
    gtk_widget_set_size_request(picture, 200, 200);
    // button
    GtkWidget *button = gtk_button_new();
    gtk_widget_set_hexpand(button, TRUE);
    gtk_widget_set_vexpand(button, TRUE);
    gtk_window_set_child(GTK_WINDOW(window), button);
    g_signal_connect(button, "clicked", G_CALLBACK(createfire), NULL);

    gtk_button_set_child(GTK_BUTTON(button), picture);

    gtk_window_present(GTK_WINDOW(window));

}

static void activate(GtkApplication *app, gpointer user_data) {
  createdemon(app);
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




