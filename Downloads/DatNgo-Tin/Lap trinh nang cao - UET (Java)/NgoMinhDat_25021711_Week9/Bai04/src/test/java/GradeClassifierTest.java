import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;
import java.io.File;
import java.nio.file.Path;
import java.nio.file.Paths;

public class GradeClassifierTest {

    // --- Các test case hợp lệ (EP + BVA) ---
    @Test
    void testYeu_Valid() {
        assertEquals("Yếu", GradeClassifier.classifyGrade(0.0));
        assertEquals("Yếu", GradeClassifier.classifyGrade(2.5));
        assertEquals("Yếu", GradeClassifier.classifyGrade(4.999));
    }

    @Test
    void testTrungBinh_Valid() {
        assertEquals("Trung bình", GradeClassifier.classifyGrade(5.0));
        assertEquals("Trung bình", GradeClassifier.classifyGrade(5.5));
        assertEquals("Trung bình", GradeClassifier.classifyGrade(6.499));
    }

    @Test
    void testKha_Valid() {
        assertEquals("Khá", GradeClassifier.classifyGrade(6.5));
        assertEquals("Khá", GradeClassifier.classifyGrade(7.0));
        assertEquals("Khá", GradeClassifier.classifyGrade(7.999));
    }

    @Test
    void testGioi_Valid() {
        assertEquals("Giỏi", GradeClassifier.classifyGrade(8.0));
        assertEquals("Giỏi", GradeClassifier.classifyGrade(9.0));
        assertEquals("Giỏi", GradeClassifier.classifyGrade(10.0));
    }

    // --- Các test case ngoại lệ (sẽ chạy sau khi sửa code) ---
    @Test
    void testInvalidGPA_ThrowsException() {
        Exception ex1 = assertThrows(IllegalArgumentException.class,
                () -> GradeClassifier.classifyGrade(-0.1));
        assertEquals("GPA không hợp lệ: -0.1", ex1.getMessage());

        Exception ex2 = assertThrows(IllegalArgumentException.class,
                () -> GradeClassifier.classifyGrade(10.1));
        assertEquals("GPA không hợp lệ: 10.1", ex2.getMessage());
    }

    // --- Test case với đường dẫn tệp tin cross-platform ---
    // Sử dụng java.nio.file.Path để đảm bảo hoạt động trên mọi hệ điều hành
    @Test
    void testFilePath_CrossPlatform() {
        // Sử dụng java.nio.file.Paths để tạo đường dẫn cross-platform
        Path path = Paths.get("data", "grades.txt");
        
        // Kiểm tra đường dẫn được tạo đúng
        assertNotNull(path);
        assertEquals("grades.txt", path.getFileName().toString());
        
        // Chuyển đổi sang File object nếu cần
        File file = path.toFile();
        assertEquals("grades.txt", file.getName());
        
        // Kiểm tra path separator phù hợp với hệ điều hành hiện tại
        String expectedSeparator = File.separator;
        assertTrue(path.toString().contains(expectedSeparator) || 
                   path.toString().contains("/") || 
                   path.toString().contains("\\"));
    }
}