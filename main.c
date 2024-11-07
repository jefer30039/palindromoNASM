#include <gtk/gtk.h>
#include <stdbool.h>

extern bool es_palindromo(const char *cadena);

char* crear_label(gpointer data){
    const char *cadena = gtk_entry_get_text(GTK_ENTRY(data));
    //obtener el tamano de cadena
    //int length = sizeof(cadena);
    if (es_palindromo(cadena)) {
        return g_strdup_printf("La cadena \"%s\" es un palíndromo", cadena);
    } else {
        return g_strdup_printf("La cadena \"%s\" no es un palíndromo", cadena);
    }
}

void mostrar_resultado(GtkWidget *widget, gpointer data)
{
    GtkWidget *vbox = gtk_widget_get_parent(widget);
    GtkWidget *windowResult;
    GtkWidget *result_label = gtk_label_new(crear_label(data));

    //ventana emergente para mostrar el resultado
    windowResult = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(windowResult), "Resultado");
    gtk_window_set_default_size(GTK_WINDOW(windowResult), 250, 100);
    gtk_container_set_border_width(GTK_CONTAINER(windowResult), 10);

    gtk_container_add(GTK_CONTAINER(windowResult), result_label);

    gtk_widget_show_all(windowResult);

}

int main (int argc, char *argv[])
{
    GtkWidget *window;
    GtkWidget *label;
    GtkWidget *entry;
    GtkWidget *button;
    GtkWidget *hbox;
    GtkWidget *vbox;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Verificar palindromos");
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);

    //etiqueta para ingresar el año
    label = gtk_label_new("Ingrese el texto:");

    //cuadro de texto para ingresar el año
    entry = gtk_entry_new();
    gtk_widget_set_halign(entry, GTK_ALIGN_CENTER);
    gtk_widget_set_valign(entry, GTK_ALIGN_END);
    gtk_widget_set_size_request(entry, 150, 30);

    //boton para calcular si el año es bisiesto
    button = gtk_button_new_with_label("Verificar");
    gtk_widget_set_size_request(button, 150, 30); // Ajusta el tamaño del botón
    gtk_widget_set_halign(button, GTK_ALIGN_CENTER); // Alinea el botón al centro horizontalmente
    gtk_widget_set_valign(button, GTK_ALIGN_START); // Alinea el botón al centro verticalmente
    g_signal_connect(button, "clicked", G_CALLBACK(mostrar_resultado), entry);

    //contenedor para los elementos
    hbox = gtk_box_new(TRUE, 1);
    vbox = gtk_box_new(FALSE, 5);

    gtk_box_pack_start(GTK_BOX(vbox), label, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(hbox), entry, TRUE, TRUE, 7);
    gtk_box_pack_start(GTK_BOX(hbox), button, TRUE, TRUE, 7); 
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(window), vbox);

    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}

